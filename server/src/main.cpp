#include <QCoreApplication>
#include "inc/server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);    
    Server server;
    if (!server.starServer(3333)){
        qDebug() << "Ошибка: " << server.errorString();
        return 1;
    }
    qDebug() << "Сревер старт...";
    return a.exec();
}
