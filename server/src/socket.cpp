#include "inc/socket.h"

Socket::Socket(qintptr handle, QObject *parent) : QTcpSocket(parent)
{
    setSocketDescriptor(handle);

    connect(this, &Socket::readyRead, [&] () {
        emit ReadyRead(this);
    });
    connect(this, &Socket::stateChanged, [&] (int x){
        emit StateChanged(this, x);
    });
}
