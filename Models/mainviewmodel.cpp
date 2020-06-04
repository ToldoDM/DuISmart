#include "mainviewmodel.h"

MainViewModel::MainViewModel() : BaseModel() {}

MainViewModel::~MainViewModel(){
    for (int i=0; i<rooms->size(); ++i) {
        delete (*rooms)[i];
    }
    delete rooms;
}

const QString& MainViewModel::addRoom(QString *newRoom){
    rooms->append(newRoom);
    return *newRoom;
}

QList<const QString*>* MainViewModel::getRoomList(){ return rooms; }

DeviceListItem* MainViewModel::addDevice(SmartDevice* newDevice){
    deviceList.insert(deviceList.end(), newDevice);
    ListDevice* ld = dynamic_cast<ListDevice*>(newDevice);
    return ld ? ld->getListType(newDevice->deviceId) : nullptr;
}

const SmartDevice* MainViewModel::getDevice(int deviceId) const{
    bool found = false;
    const SmartDevice* dev = nullptr;

    for(auto it = deviceList.begin(); it != deviceList.end() && !found; ++it) {
        dev = *it;
        if(dev->deviceId == deviceId) found = true;
    }

    return dev;
}


