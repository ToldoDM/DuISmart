#include "controller.h"

Controller::Controller(QObject* parent) : QObject(parent){
    MainVM = new MainViewModel();
    MainW = new MainWindow();

    //Connessioni segnali e slot
    connect(MainW, SIGNAL(addNewDevice()), this, SLOT(riseAddWindow()));
}

void Controller::ShowMainWindow() const { MainW->show(); }

void Controller::addSmartDeviceToList(SmartDevice *device) const{
    DeviceListItem* dli = MainVM->addDevice(device);
    MainW->addToAllTab(dli);
}

void Controller::riseAddWindow(){
    //secondaFinestra ha l'unica funzione di permettere ad exec di bloccare la prima finestra
    secondaFinestra = new QDialog();
    AddItemW = new AddItemWindow(secondaFinestra);
    AddItemVM = new AddItemModel();

    //Connessioni segnali e slot
    connect(AddItemW, SIGNAL(onDeviceNameChanged(const QString&)), this, SLOT(setDeviceNameChanged(const QString&)));
    connect(AddItemW, SIGNAL(onFriendlyNameChanged(const QString&)), this, SLOT(setFriendlyNameChanged(const QString&)));
    connect(AddItemW, SIGNAL(onAddNewDevice()), this, SLOT(addNewDeviceToMainW()));

    AddItemW->exec();
}

void Controller::setDeviceNameChanged(const QString& text) const{
    AddItemVM->deviceName = text;
}

void Controller::setFriendlyNameChanged(const QString& text) const{
    AddItemVM->friendlyName = text;
}

void Controller::addNewDeviceToMainW() const{
    addSmartDeviceToList(new Bulb(0));
    delete AddItemW;
    delete AddItemVM;
}
