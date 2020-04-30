#include "controller.h"

Controller::Controller(QObject* parent) : QObject(parent){
    MainVM = new MainViewModel();
    MainW = new MainWindow(MainVM);

    connect(MainW, SIGNAL(notifyController()), this, SLOT(notifyHandler()));
}

void Controller::ShowMainWindow() const { MainW->show(); }

void Controller::notifyHandler(){
    //qui viene gestito l'evento emesso da MainW.notifyController()
    //devo fare anche un notuifuy al model x
    MainVM->FaiQualcosa();
}

//in questa classe gestisco tutte le viste e i model
