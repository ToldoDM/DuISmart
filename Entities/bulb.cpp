#include "bulb.h"

Bulb::Bulb(const int& devID, const QString& fName) : SmartDevice(devID, fName) {}

DeviceListItem* Bulb::getListType() const {
    return new BulbListItem(deviceId, friendlyName);
}
