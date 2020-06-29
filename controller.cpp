#include "controller.h"


Controller::Controller(QObject* parent) : QObject(parent){
    MainVM = new MainViewModel();
    MainW = new MainWindow();

    fileIO = new TxtManager();
    
    //Connessioni segnali e slot
    connect(MainW, SIGNAL(addNewDevice()), this, SLOT(riseAddWindow()));
    connect(MainW,SIGNAL(onRemoveRoom(const QString&)),this,SLOT(removeRoomFromModel(const QString&)));

    connect(fileIO,SIGNAL(readedData(const QString&, const QString&)),this, SLOT(insertData(const QString&, const QString&)));
    // caricare file se sono salvati
    fileIO->readData();
}

//PUBLIC METHODS
void Controller::ShowMainWindow() const { MainW->show(); MainW->setFixedSize(640,480); }

//PRIVATE METHODS
// metodo che permette l'aggiunta di un nuovo device in un tab
DeviceListItem* Controller::addSmartDeviceToList(SmartDevice *device, const QString& targetTab) const{
    DeviceListItem* dli = MainVM->addDevice(device);
    MainW->addToAllTab(dli, targetTab);

    //connessione bottone impostazioni
    connect(dli,SIGNAL(SettingPressed(DeviceListItem*)),this,SLOT(selectSettings(DeviceListItem*)));

    //connessione bottone delete
    connect(dli, SIGNAL(deleteRequest(QListWidgetItem*, int)), this, SLOT(removeSmartDeviceFromList(QListWidgetItem*, int)));

    return dli;
}

//PRIVATE SLOTS
void Controller::removeRoomFromModel(const QString& roomName){ MainVM->removeRoom(roomName); }

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
    SmartDevice* device= nullptr;
    DeviceListItem* dli = nullptr;
    switch (dType) {
    case DeviceType::BULB:
        device = new Bulb(idCount++, AddItemVM->getFName());
        //fileIO->writeData(BULB,idCount,roomName);
        break;
    case DeviceType::TV:
        device = new Tv(idCount++, AddItemVM->getFName());
        //fileIO->writeData(TV,idCount,roomName);
        break;
    case DeviceType::THERMOSTAT:
        device = new Thermostat(idCount++, AddItemVM->getFName());
        //fileIO->writeData(THERMOSTAT,idCount,roomName);
        break;
    }


    //Alle volte per ragioni a noi sconosciute, lancia un seg-fault alla addItemW->Close();
    try {
        dli = addSmartDeviceToList(device, roomName);
        AddItemW->close();
    } catch (...) {
        QErrorMessage mb(MainW);
        mb.showMessage(tr("Aggiunta device non riuscita"));
        mb.exec();
        if(dli) {
            removeSmartDeviceFromList(dli->getListItem(), --idCount);
        }
    }
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

    //Prendo le impostazioni del corrente device e le passo alla finestra
    SettingData* data = MainVM->getDeviceSettings(dli->getDeviceID());
    settW = dli->getSettingDialog(*data);

    //Connessione slot
    connect(settW,SIGNAL(onSetNewSettings(const SettingData&)),dli,SLOT(setSettings(const SettingData&)));
    connect(settW,SIGNAL(onSetNewSettings(const SettingData&)),this,SLOT(setSettings(const SettingData&)));
    connect(settW, SIGNAL(finished(int)), this, SLOT(settWinClosed()));

    settW->exec();

    //elimino il settingdata
    delete data;
}

void Controller::setSettings(const SettingData& data){
    MainVM->setDeviceSettings(data);
}

void Controller::settWinClosed(){
    settW->close();
    delete settW;
    settW = nullptr;
}

void Controller::removeSmartDeviceFromList(QListWidgetItem* qli, int deviceID) const{
    //Tramite qli trovo l'oggetto deviceList della lista e lo cancello
    MainW->removeFromTab(qli);
    //Cancellato il qli, successivamente cancello lo smartDevice dalla lista device
    MainVM->removeDevice(deviceID);
}







