#include <QApplication>
#include <QResource>
#include <controller.h>

int main(int argc, char *argv[])
{
    QResource::registerResource("resources.qrc");
    QApplication a(argc, argv);
    Controller c;
    c.ShowMainWindow();

    return a.exec();
}
