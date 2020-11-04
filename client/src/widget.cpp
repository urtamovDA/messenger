#include "inc/widget.h"
#include "./ui_widget.h"
#include "inc/connection.h"
#include <QTcpSocket>
#include <QTextStream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    mSocket = new QTcpSocket(this);
    connect(mSocket, &QTcpSocket::readyRead, [&](){
        QTextStream ts(mSocket);
        auto text = ts.readAll();
        ui->textEdit->append(text);
    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_send_clicked()
{
    QTextStream tr(mSocket);
    tr << ui->nickname->text() << ": " << ui->message->text();
    mSocket->flush();
    ui->message->clear();
}

void Widget::on_bind_clicked()
{
    Connection con(this);
    if (con.exec() == QDialog::Rejected){
        return;
    }
    mSocket->connectToHost(con.HostName(), con.Port());
}
