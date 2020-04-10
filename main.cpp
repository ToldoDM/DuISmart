#include "duismart.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DuiSmart w;
    w.show();
    //commento
    return a.exec();
}
