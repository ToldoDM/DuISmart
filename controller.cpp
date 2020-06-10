#include "controller.h"

Controller::Controller(QObject* parent) : QObject(parent){
    MainVM = new MainViewModel();
    MainW = new MainWindow();

    //connessioni segnali e slot
    connect(MainW,SIGNAL(AccSettingsBulb()),this,SLOT(riseBulbSettingsWindow()));

    connect(MainW,SIGNAL(AccSettingsDisplay()),this, SLOT(riseDisplaySettings()));


    //Connessioni segnali e slot
    connect(MainW, SIGNAL(addNewDevice()), this, SLOT(riseAddWindow()));
}

void Controller::ShowMainWindow() const { MainW->show(); }

//in questa classe gestisco tutte le viste e i model


void Controller::riseBulbSettingsWindow(){

    /*BulbS=new BulbSettings();
    BulbS->show();


    //connessione per intercettare dati estratti
    connect(BulbS, SIGNAL(extractedData(const QColor,const int)),this,SLOT(getBulbSettings(const QColor, const int)));
*/
    TherS=new thermostatSettings();
    TherS->show();
}

void Controller::getBulbSettings(const QColor colore, const int valore){
    //fare qualcosa con i valori restituiti
}

void Controller::riseDisplaySettings(){

    DispS= new DisplaySettings();
    DispS->show();
}

void Controller::getDisplaySettings(const int contrast, const int brightness){
    //fare qualcosa

void Controller::addSmartDeviceToList(SmartDevice *device, const QString& targetTab) const{
    DeviceListItem* dli = MainVM->addDevice(device);
    MainW->addToAllTab(dli, targetTab);
}

void Controller::riseAddWindow(){
    //secondaFinestra ha l'unica funzione di permettere ad exec di bloccare la prima finestra
    auto list = MainVM->getRoomList();
    AddItemVM = new AddItemModel(list);
    AddItemW = new AddItemWindow();

    AddItemW->populateRoomsComboBox(list);

    //Connessioni segnali e slot
    connect(AddItemW, SIGNAL(onDeviceNameChanged(const QString&)), this, SLOT(setDeviceNameChanged(const QString&)));
    connect(AddItemW, SIGNAL(onFriendlyNameChanged(const QString&)), this, SLOT(setFriendlyNameChanged(const QString&)));
    connect(AddItemW, SIGNAL(onAddNewDevice(DeviceType, const QString&)), this, SLOT(addNewDeviceToMainW(DeviceType, const QString&)));
    connect(AddItemW, SIGNAL(onAddNewRoom(const QString&)), this, SLOT(addNewRoom(const QString&)));
    connect(AddItemW, SIGNAL(finished(int)), this, SLOT(addWinClosed(int)));

    AddItemW->exec();
}

void Controller::addWinClosed(int result){
    delete AddItemW;
    delete AddItemVM;
    AddItemW = nullptr;
    AddItemVM = nullptr;
}

void Controller::addNewRoom(const QString& roomName) const{
    MainVM->addRoom(new QString(roomName));
    MainW->addTab(roomName);
}

void Controller::setDeviceNameChanged(const QString& text) const{ AddItemVM->setDName(text); }

void Controller::setFriendlyNameChanged(const QString& text) const{ AddItemVM->setFName(text); }

void Controller::addNewDeviceToMainW(DeviceType dType, const QString& roomName){
    switch (dType) {
    case DeviceType::BULB:
        //ATTENZIONE!!! da rendere l'id del device univoco
        addSmartDeviceToList(new Bulb(0, AddItemVM->getFName()), roomName);
        break;
    case DeviceType::TV:
        //addSmartDeviceToList(new Bulb(0), roomName);
        break;
    case DeviceType::THERMOSTAT:
        //addSmartDeviceToList(new Bulb(0), roomName);
        break;
    }

    AddItemW->close();
}
