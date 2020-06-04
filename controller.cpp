#include "controller.h"

Controller::Controller(QObject* parent) : QObject(parent){
    MainVM = new MainViewModel();
    MainW = new MainWindow();

    //Connessioni segnali e slot
    connect(MainW, SIGNAL(addNewDevice()), this, SLOT(riseAddWindow()));

    //Aggiunta tab default
    MainW->addTab(MainVM->addRoom(new QString("All")), true);
}

void Controller::ShowMainWindow() const { MainW->show(); }

void Controller::addSmartDeviceToList(SmartDevice *device, const QString& targetTab) const{
    DeviceListItem* dli = MainVM->addDevice(device);
    MainW->addToAllTab(dli, targetTab);
}

void Controller::riseAddWindow(){
    //secondaFinestra ha l'unica funzione di permettere ad exec di bloccare la prima finestra
    secondaFinestra = new QDialog();
    AddItemW = new AddItemWindow(secondaFinestra);
    AddItemVM = new AddItemModel(MainVM->getRoomList());

    //Connessioni segnali e slot
    connect(AddItemW, SIGNAL(onDeviceNameChanged(const QString&)), this, SLOT(setDeviceNameChanged(const QString&)));
    connect(AddItemW, SIGNAL(onFriendlyNameChanged(const QString&)), this, SLOT(setFriendlyNameChanged(const QString&)));
    connect(AddItemW, SIGNAL(onAddNewDevice()), this, SLOT(addNewDeviceToMainW()));

    AddItemW->exec();
}

void Controller::setDeviceNameChanged(const QString& text) const{ AddItemVM->setDName(text); }

void Controller::setFriendlyNameChanged(const QString& text) const{ AddItemVM->setFName(text); }

void Controller::addNewDeviceToMainW() const{
    //addSmartDeviceToList(new Bulb(0));
    delete AddItemW;
    delete AddItemVM;
}
