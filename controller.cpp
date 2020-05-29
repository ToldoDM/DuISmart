#include "controller.h"

Controller::Controller(QObject* parent) : QObject(parent){
    MainVM = new MainViewModel();
    MainW = new MainWindow(MainVM);
}

void Controller::ShowMainWindow() const { MainW->show(); }

void Controller::addSmartDeviceToList(SmartDevice *device) const{
    DeviceListItem* dli = MainVM->addDevice(device);
    MainW->addToAllTab(dli);
}

//in questa classe gestisco tutte le viste e i model
