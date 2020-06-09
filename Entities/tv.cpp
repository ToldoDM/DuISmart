#include "tv.h"

Tv::Tv(const int& devID, const QString& fName) : SmartDevice(devID, fName){}

DeviceListItem* Tv::getListType() const {
    return new TvListItem(deviceId, friendlyName);
}


