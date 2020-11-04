#ifndef SOCKET_H
#define SOCKET_H

#include <QTcpSocket>

class Socket : public QTcpSocket
{
    Q_OBJECT

public:
    Socket(qintptr handle, QObject *parent = nullptr);

signals:
    void ReadyRead(Socket *);
    void StateChanged(Socket *, int);
};

#endif // SOCKET_H
