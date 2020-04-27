#include "mainwindow.h"

MainWindow::MainWindow(MainViewModel* model, QWidget *parent) : QWidget(parent)
{
    this->model = model;

    setWindowTitle ("DuISmartMainWindow");
    button = new QPushButton("bottone prova",this);
    button->show();
}
