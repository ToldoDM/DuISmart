#include "mainviewmodel.h"


MainViewModel::MainViewModel() : BaseModel() {
    rooms = new QList<const QString*>();
}

MainViewModel::~MainViewModel(){
    for (int i=0; i<rooms->size(); ++i) {
        delete (*rooms)[i];
    }
    delete rooms;
}

void MainViewModel::addRoom(const QString *newRoom){
    rooms->append(newRoom);
}

void MainViewModel::removeDevice(int devId){
    const SmartDevice* dev = nullptr;
     for (int i=0; i<deviceList.size() && !dev; i++) {
         dev = deviceList[i]->isThisDevice(devId);
         if(dev){
             deviceList.erase(dev);
         }
     }
}

QList<const QString*>* MainViewModel::getRoomList(){ return rooms; }

DeviceListItem* MainViewModel::addDevice(SmartDevice* newDevice){
    deviceList.push(newDevice);
    ListDevice* ld = dynamic_cast<ListDevice*>(newDevice);
    return ld ? ld->getListType() : nullptr;
}

const SmartDevice* MainViewModel::getDevice(int deviceId) const{
    const SmartDevice* dev = nullptr;
    for (int i=0; i<deviceList.size(); i++) { dev = deviceList[i]->isThisDevice(deviceId); }
    return dev;
}


