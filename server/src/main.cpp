#include <QCoreApplication>
#include "inc/server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);    
    Server server;
    if (!server.starServer(3333)){
        qDebug() << "Error: " << server.errorString();
        return 1;
    }
    qDebug() << "Server start...";
    return a.exec();
}
