#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle ("DuISmartMainWindow");
    button = new QPushButton("bottone prova",this);
    button->show();
}
