#include "inc/connection.h"
#include "ui_connection.h"

Connection::Connection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connection)
{
    ui->setupUi(this);
}

Connection::~Connection()
{
    delete ui;
}

QString Connection::HostName() const
{
    return hostname;
}

quint16 Connection::Port() const
{
    return port;
}

void Connection::on_ok_clicked()
{
    hostname = ui->hostname->text();
    port = ui->port->value();
    accept();
}

void Connection::on_cancel_clicked()
{
    reject();
}
