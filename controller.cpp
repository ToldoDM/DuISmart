#include "controller.h"


Controller::Controller(QObject* parent) : QObject(parent){
    MainVM = new MainViewModel();
    MainW = new MainWindow();

    fileIO = new TxtManager();
    
    //Connessioni segnali e slot
    connect(MainW, SIGNAL(addNewDevice()), this, SLOT(riseAddWindow()));

    connect(fileIO,SIGNAL(readedData(const QString&, const QString&)),this, SLOT(insertData(const QString&, const QString&)));
    // caricare file se sono salvati
    fileIO->readData();
}

//PUBLIC METHODS
void Controller::ShowMainWindow() const { MainW->show(); }

//PRIVATE METHODS
// metodo che permette l'aggiunta di un nuovo device in un tab
void Controller::addSmartDeviceToList(SmartDevice *device, const QString& targetTab) const{
    DeviceListItem* dli = MainVM->addDevice(device);
    MainW->addToAllTab(dli, targetTab);

    //connessione bottone impostazioni
    connect(dli,SIGNAL(SettingPressed(DeviceListItem*)),this,SLOT(selectSettings(DeviceListItem*)));

    //connessione bottone delete
    connect(dli, SIGNAL(deleteRequest(QListWidgetItem*, int)), this, SLOT(removeSmartDeviceFromList(QListWidgetItem*, int)));

    connect(this,SIGNAL(changeChan(int,int)),dli,SLOT(changeLabelChan(int,int)));
    connect(this,SIGNAL(changeTemp(int,int)),dli,SLOT(changeLabelTemp(int,int)));
}

//PRIVATE SLOTS
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
    connect(AddItemW, SIGNAL(finished(int)), this, SLOT(addWinClosed()));

    AddItemW->exec();
}

void Controller::setDeviceNameChanged(const QString& text) const{ AddItemVM->setDName(text); }


void Controller::setFriendlyNameChanged(const QString& text) const{ AddItemVM->setFName(text); }


void Controller::addNewDeviceToMainW(DeviceType dType, const QString& roomName){
    switch (dType) {
    case DeviceType::BULB:
        addSmartDeviceToList(new Bulb(idCount++, AddItemVM->getFName()), roomName);
        fileIO->writeData(BULB,idCount,roomName);
        break;
    case DeviceType::TV:
        addSmartDeviceToList(new Tv(idCount++, AddItemVM->getFName()), roomName);
        fileIO->writeData(TV,idCount,roomName);
        break;
    case DeviceType::THERMOSTAT:
        addSmartDeviceToList(new Thermostat(idCount++, AddItemVM->getFName()), roomName);
        fileIO->writeData(THERMOSTAT,idCount,roomName);
        break;
    }
    AddItemW->close();
}

void Controller::addNewRoom(const QString& roomName) const{
    MainVM->addRoom(new QString(roomName));
    MainW->addTab(roomName);
}

void Controller::addWinClosed(){
    delete AddItemW;
    delete AddItemVM;
    AddItemW = nullptr;
    AddItemVM = nullptr;
}

void Controller::insertData(const QString& tipo, const QString& room_name)
{
    /*if(tipo=="0"){
        addNewDeviceToMainW(BULB,room_name);
    }
    else if(tipo=="1"){
        addNewDeviceToMainW(TV,room_name);
    }
    else{
        addNewDeviceToMainW(THERMOSTAT,room_name);
    }*/

}

//slot la cui funzione è quella di direzionare a quale finestra di impostazioni si riferisce il segnale settingpressed
void Controller::selectSettings(DeviceListItem* dli){

    settW = dli->getSettingDialog();

    //Connessione slot
    connect(settW,SIGNAL(setNewChannel(int,int)),this,SLOT(getChannel(int,int)));
    connect(settW,SIGNAL(ThermostatExtractedData(int,int)),this,SLOT(getTemp(int,int)));
    connect(settW, SIGNAL(finished(int)), this, SLOT(settWinClosed()));

    settW->exec();
}

void Controller::settWinClosed(){
    delete settW;
    settW = nullptr;
}

void Controller::getChannel(int ID,int channel){
    emit changeChan(ID,channel);
}

void Controller::getTemp(int ID,int temp){
    emit changeTemp(ID,temp);
}

void Controller::removeSmartDeviceFromList(QListWidgetItem* qli, int deviceID) const{
    //Tramite qli trovo l'oggetto deviceList della lista e lo cancello
    MainW->removeFromTab(qli);
    //Cancellato il qli, successivamente cancello lo smartDevice dalla lista device
    MainVM->removeDevice(deviceID);
    //Controllo se il tab dove era il device e se non ci sono piu device lo cancello
}

void Controller::extractedDataBulb(const QColor, const int)
{
    //emit something
}

void Controller::extractedDataTv(int, int)
{
    //emit something
}









