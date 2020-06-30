#include "tv.h"

Tv::Tv(const int& devID, const QString& fName) : SmartDevice(devID, fName){}

DeviceListItem* Tv::getListType() const {
    return new TvListItem(deviceId, friendlyName);
}

void Tv::switchOnDevice() const {
    //Logica per accensione
}

void Tv::switchOffDevice() const {
    //Logica per spegnimento
}

void Tv::setSettings(const SettingData &data){
    contrast = data.contrast;
    brightness = data.brightness;
    channel = data.channel;
}

SettingData* Tv::getSettings() const {
    SettingData* data = new SettingData(deviceId);
    data->contrast = contrast;
    data->brightness = brightness;
    data->channel = channel;
    return data;
}
