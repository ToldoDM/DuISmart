#include "mainwindow.h"

MainWindow::MainWindow(MainViewModel* model, QWidget *parent) : QWidget(parent)
{
    this->model = model;

    setWindowTitle ("DuISmartMainWindow");
    setFixedSize(400,400);
    tab = new QTabBar(this);
    tab->addTab("test");
    tab->addTab("test1");
    tab->show();
    tab->resize(165, 165);

    button = new QPushButton("bottone prova",this);
    button->show();
}
