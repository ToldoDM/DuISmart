#include "controller.h"

Controller::Controller(QObject* parent) : QObject(parent){
    MainVM = new MainViewModel();
    MainW = new MainWindow();

    fileIO = new TxtManager();
    
    //Connessioni segnali e slot
    connect(MainW, SIGNAL(addNewDevice()), this, SLOT(riseAddWindow()));

    connect(fileIO,SIGNAL(readedData(QString,QString)),this, SLOT(insertData(QString,QString)));
    // caricare file se sono salvati
    fileIO->readData();
}

void Controller::ShowMainWindow() const { MainW->show(); }

// metodo che permette l'aggiunta di un nuovo device in un tab
void Controller::addSmartDeviceToList(SmartDevice *device, const QString& targetTab) const{
    DeviceListItem* dli = MainVM->addDevice(device);
    MainW->addToAllTab(dli, targetTab);
    connect(dli,SIGNAL(SettingPressed(DeviceType,int)),this,SLOT(selectSettings(DeviceType,int)));
}

//slot la cui funzione è quella di direzionare a quale finestra di impostazioni si riferisce il segnale settingpressed
void Controller::selectSettings(DeviceType type, int IDNumber) const
{
    switch (type) {
    case DeviceType::BULB:
        BulbS= new BulbSettings();
        //void Controller::getBulbSettings(int brightness , const int contrast)){}
        BulbS->show();
        break;

    case DeviceType::TV:
        DispS=new DisplaySettings() ;
        DispS->show();
        //void Controller::getDisplaySettings(const int contrast, const int brightness){}

        break;

    case DeviceType::THERMOSTAT:
        TherS=new ThermostatSettings();
        TherS->show();
        //void Controller::getThermostatSettings(int temp){}
        break;
    }

}

void Controller::insertData(QString tipo, QString room_name)
{
    if(tipo=="0"){
        addNewDeviceToMainW(BULB,room_name);
    }
    else if(tipo=="1"){
        addNewDeviceToMainW(TV,room_name);
    }
    else{
        addNewDeviceToMainW(THERMOSTAT,room_name);
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
        fileIO->writeData(BULB,idCount++,roomName);
        addSmartDeviceToList(new Bulb(idCount, AddItemVM->getFName()), roomName);
        break;
    case DeviceType::TV:
        fileIO->writeData(TV,idCount++,roomName);
        addSmartDeviceToList(new Tv(idCount, AddItemVM->getFName()), roomName);
        break;
    case DeviceType::THERMOSTAT:
        fileIO->writeData(THERMOSTAT,idCount++,roomName);
        addSmartDeviceToList(new Thermostat(idCount, AddItemVM->getFName()), roomName);
        break;
    }
    AddItemW->close();
}

