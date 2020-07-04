#include "controller.h"


Controller::Controller(QObject* parent) : QObject(parent){
    MainVM = new MainViewModel();
    MainW = new MainWindow();
    
    //Connessioni segnali e slot
    connect(MainW, SIGNAL(addNewDevice()), this, SLOT(riseAddWindow()));
    connect(MainW,SIGNAL(onRemoveRoom(const QString&)),this,SLOT(removeRoomFromModel(const QString&)));
}

void Controller::ShowMainWindow() const { MainW->show(); MainW->setFixedSize(640,480); }

// metodo che permette l'aggiunta di un nuovo device in un tab
DeviceListItem* Controller::addSmartDeviceToList(SmartDevice *device, const QString& targetTab) const{
    DeviceListItem* dli = MainVM->addDevice(device);
    MainW->addToAllTab(dli, targetTab);

    //connessione bottone impostazioni
    connect(dli,SIGNAL(SettingPressed(DeviceListItem*)),this,SLOT(selectSettings(DeviceListItem*)));

    //connessione bottone delete
    connect(dli, SIGNAL(deleteRequest(QListWidgetItem*, int)), this, SLOT(removeSmartDeviceFromList(QListWidgetItem*, int)));

    //connessione bottone on/off
    connect(dli, SIGNAL(setDeviceOn(bool)), device, SLOT(onSetDeviceState(bool)));

    return dli;
}

void Controller::removeRoomFromModel(const QString& roomName){ MainVM->removeRoom(roomName); }

void Controller::riseAddWindow(){
    auto list = MainVM->getRoomList();
    AddItemVM = new AddItemModel(list);
    AddItemW = new AddItemWindow();

    AddItemW->populateRoomsComboBox(list);

    //Connessioni segnali e slot
    connect(AddItemW, SIGNAL(onFriendlyNameChanged(const QString&)), this, SLOT(setFriendlyNameChanged(const QString&)));
    connect(AddItemW, SIGNAL(onAddNewDevice(DeviceType, const QString&)), this, SLOT(addNewDeviceToMainW(DeviceType, const QString&)));
    connect(AddItemW, SIGNAL(onAddNewRoom(const QString&)), this, SLOT(addNewRoom(const QString&)));
    connect(AddItemW, SIGNAL(closeAddItemW()), this, SLOT(addWinClosed()));

    AddItemW->setFixedSize(400,200);
    AddItemW->exec();
}

void Controller::setFriendlyNameChanged(const QString& text) const{ AddItemVM->setFName(text); }


void Controller::addNewDeviceToMainW(DeviceType dType, const QString& roomName){
    SmartDevice* device= nullptr;
    DeviceListItem* dli = nullptr;
    switch (dType) {
    case DeviceType::BULB:
        device = new Bulb(idCount++, AddItemVM->getFName());
        break;
    case DeviceType::TV:
        device = new Tv(idCount++, AddItemVM->getFName());
        break;
    case DeviceType::THERMOSTAT:
        device = new Thermostat(idCount++, AddItemVM->getFName());
        break;
    }


    try {
        dli = addSmartDeviceToList(device, roomName);
        if(!AddItemW) throw new std::exception();
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

//slot la cui funzione è quella di direzionare a quale finestra di impostazioni si riferisce il segnale settingpressed
void Controller::selectSettings(DeviceListItem* dli){

    //Prendo le impostazioni del corrente device e le passo alla finestra
    SettingData* data = MainVM->getDeviceSettings(dli->getDeviceID());
    settW = dli->getSettingDialog(*data);

    //Connessione slot
    connect(settW,SIGNAL(onSetNewSettings(const SettingData&)),dli,SLOT(setSettings(const SettingData&)));
    connect(settW,SIGNAL(onSetNewSettings(const SettingData&)),this,SLOT(setSettings(const SettingData&)));
    connect(settW, SIGNAL(onCloseSettW()), this, SLOT(settWinClosed()));

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







