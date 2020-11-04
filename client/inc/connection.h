#ifndef CONNECTION_H
#define CONNECTION_H

#include <QDialog>

namespace Ui {
class Connection;
}

class Connection : public QDialog
{
    Q_OBJECT

public:
    explicit Connection(QWidget *parent = nullptr);
    ~Connection();
    QString HostName() const;
    quint16 Port() const;

private slots:
    void on_ok_clicked();

    void on_cancel_clicked();

private:
    Ui::Connection *ui;
    QString hostname;
    quint16 port;
};

#endif // CONNECTION_H
