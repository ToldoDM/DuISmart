#include "controller.h"

Controller::Controller(QObject* parent) : QObject(parent){
    MainVM = new MainViewModel();
    MainW = new MainWindow(MainVM);
}

void Controller::ShowMainWindow() const { MainW->show(); }

//in questa classe gestisco tutte le viste e i model
