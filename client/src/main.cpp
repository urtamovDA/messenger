#include "inc/widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("funsion");
    Widget w;
    w.show();
    return a.exec();
}
