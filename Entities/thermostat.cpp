#include "thermostat.h"

Thermostat::Thermostat(const int& devID, const QString& fName) : SmartDevice(devID, fName){}

DeviceListItem* Thermostat::getListType() const {
    return new ThermoListItem(deviceId, friendlyName);
}

