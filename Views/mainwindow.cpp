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

    connect(button,SIGNAL(clicked()),this,SLOT(clieckedHandler()));
    connect(this->model,SIGNAL(refreshView()), this, SLOT(refresh()));
}

void MainWindow::clieckedHandler(){
    emit notifyController();
}

void MainWindow::refresh(){
    //qui gestisco l'evento generato da MainVW (in questa classe si chiama model)
}
