#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>

class Socket;
class Server : public QTcpServer
{
public:
    Server(QObject *parent = nullptr);
    bool starServer(quint16 port);

protected:
    void incomingConnection(qintptr handle);

private:
    QList<Socket*> mSocked;
};

#endif // SERVER_H
