#include "controller.h"

Controller::Controller(QObject* parent) : QObject(parent){
    MainVM = new MainViewModel();
    MainW = new MainWindow();

    //Connessioni segnali e slot
    connect(MainW, SIGNAL(addNewDevice()), this, SLOT(riseAddWindow()));
}

void Controller::ShowMainWindow() const { MainW->show(); }

// metodo che permette l'aggiunta di un nuovo device in un tab
void Controller::addSmartDeviceToList(SmartDevice *device, const QString& targetTab) const{
    DeviceListItem* dli = MainVM->addDevice(device);
    MainW->addToAllTab(dli, targetTab);
    connect(dli,SIGNAL(SettingPressed(DeviceType,int)),this,SLOT(selectSettings(DeviceType,int)));
}

void Controller::removeSmartDeviceFromList() const{
    //Prendo il dli e tramite l'item trovo l'oggetto QlistWidgetItem della lista e lo cancello
    //Cancello il dli e successivamente cancello lo smartDevice dalla lista device
}

//slot la cui funzione è quella di direzionare a quale finestra di impostazioni si riferisce il segnale settingpressed
void Controller::selectSettings(DeviceType type, int IDNumber) const
{
    switch (type) {
    case DeviceType::BULB:
        BulbS= new BulbSettings();
        BulbS->show();
        break;

    case DeviceType::TV:
        DispS=new DisplaySettings() ;
        DispS->show();
        break;

    case DeviceType::THERMOSTAT:
        TherS=new ThermostatSettings();
        TherS->show();
        break;
    }
}

void Controller::riseAddWindow(){
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
        addSmartDeviceToList(new Bulb(idCount++, AddItemVM->getFName()), roomName);
        break;
    case DeviceType::TV:
        addSmartDeviceToList(new Tv(idCount++, AddItemVM->getFName()), roomName);
        break;
    case DeviceType::THERMOSTAT:
        addSmartDeviceToList(new Thermostat(idCount++, AddItemVM->getFName()), roomName);
        break;
    }
    AddItemW->close();
}

