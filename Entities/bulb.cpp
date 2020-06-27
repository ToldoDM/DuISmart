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

void Bulb::setSettings(const SettingData &data){
    brightness = data.brightness;
}

SettingData* Bulb::getSettings() const {
    SettingData* data = new SettingData(deviceId);
    data->brightness = brightness;
    data->red = red;
    data->green = green;
    data->blue = blue;
    return data;
}
