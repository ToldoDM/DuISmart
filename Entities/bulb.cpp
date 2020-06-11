#include "bulb.h"

Bulb::Bulb(const int& devID, const QString& fName) : SmartDevice(devID, fName) {}

DeviceListItem* Bulb::getListType() const {
    return new BulbListItem(deviceId, friendlyName);
}

void Bulb::switchOnDevice() const {
    //Logica per accensione
}

void Bulb::switchOffDevice() const {
    //Logica per spegnimento
}
