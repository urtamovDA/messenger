#include "inc/server.h"
#include "inc/socket.h"
#include <QTextStream>
#include <QDebug>

Server::Server(QObject *parent) : QTcpServer(parent)
{

}

bool Server::starServer(quint16 port)
{
    return listen(QHostAddress::Any, port);
}

void Server::incomingConnection(qintptr handle)
{
    qDebug() << "Подключился клиент: " << handle;
    auto socket = new Socket(handle, this);
    mSocked << socket;

    for (auto i : mSocked){
        QTextStream t(i);
        t << "Сервер: вы подключены " << handle;
        i->flush();
    }

    connect(socket, &Socket::ReadyRead, [&] (Socket *str){       
        QTextStream ts_1(str);
        auto text = ts_1.readAll();

        for(auto i : mSocked){
            QTextStream ts_2(i);
            ts_2 << text;
            i->flush();
        }
    });
    connect(socket, &Socket::StateChanged, [&](Socket *str, int x){        
        if (x == QTcpSocket::UnconnectedState){
            mSocked.removeOne(str);
            for(auto i : mSocked){
                QTextStream ts(i);
                ts << "Сервер: клиент " << str->socketDescriptor() << "отключился.";
                i->flush();
            };
        };
    });
}
