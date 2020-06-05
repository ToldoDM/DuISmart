#include "controller.h"

Controller::Controller(QObject* parent) : QObject(parent){
    MainVM = new MainViewModel();
    MainW = new MainWindow();

    //Connessioni segnali e slot
    connect(MainW, SIGNAL(addNewDevice()), this, SLOT(riseAddWindow()));

    //Aggiunta tab default
    QString* all = new QString("All");
    //MainVM->addRoom(all);
    MainW->addTab(*all, true);
}

void Controller::ShowMainWindow() const { MainW->show(); }

void Controller::addSmartDeviceToList(SmartDevice *device, const QString& targetTab) const{
    DeviceListItem* dli = MainVM->addDevice(device);
    MainW->addToAllTab(dli, targetTab);
}

void Controller::riseAddWindow(){
    //secondaFinestra ha l'unica funzione di permettere ad exec di bloccare la prima finestra
    secondaFinestra = new QDialog();
    QList<const QString*>* list = MainVM->getRoomList();
    AddItemVM = new AddItemModel(list);
    AddItemW = new AddItemWindow(secondaFinestra);

    AddItemW->populateRoomsComboBox(list);

    //Connessioni segnali e slot
    connect(AddItemW, SIGNAL(onDeviceNameChanged(const QString&)), this, SLOT(setDeviceNameChanged(const QString&)));
    connect(AddItemW, SIGNAL(onFriendlyNameChanged(const QString&)), this, SLOT(setFriendlyNameChanged(const QString&)));
    connect(AddItemW, SIGNAL(onAddNewDevice(int, const QString&)), this, SLOT(addNewDeviceToMainW(int, const QString&)));
    connect(AddItemW, SIGNAL(onAddNewRoom(const QString&)), this, SLOT(addNewRoom(const QString&)));

    AddItemW->exec();
}

void Controller::addNewRoom(const QString& roomName) const{
    MainVM->addRoom(&roomName);
    MainW->addTab(roomName);
}

void Controller::setDeviceNameChanged(const QString& text) const{ AddItemVM->setDName(text); }

void Controller::setFriendlyNameChanged(const QString& text) const{ AddItemVM->setFName(text); }

void Controller::addNewDeviceToMainW(int dType, const QString& roomName) const{
    switch (dType) {
    case DeviceType::BULB:
        addSmartDeviceToList(new Bulb(0), roomName);
        break;
    case DeviceType::TV:
        //addSmartDeviceToList(new Bulb(0), roomName);
        break;
    case DeviceType::THERMOSTAT:
        //addSmartDeviceToList(new Bulb(0), roomName);
        break;
    default:
        break;
    }

    AddItemW->close();
    delete AddItemW;
    delete AddItemVM;
}
