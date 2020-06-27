#include "thermostat.h"

Thermostat::Thermostat(const int& devID, const QString& fName) : SmartDevice(devID, fName){}

DeviceListItem* Thermostat::getListType() const {
    return new ThermoListItem(deviceId, friendlyName);
}

void Thermostat::switchOnDevice() const {
    //Logica per accensione
}

void Thermostat::switchOffDevice() const {
    //Logica per spegnimento
}

void Thermostat::setSettings(const SettingData &data){
    temp = data.temp;
}

SettingData* Thermostat::getSettings() const {
    SettingData* data = new SettingData(deviceId);
    data->temp = temp;
    return data;
}
