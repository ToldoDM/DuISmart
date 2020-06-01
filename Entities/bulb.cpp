#include "bulb.h"

Bulb::Bulb(const int& devID) : SmartDevice(devID) {}

DeviceListItem* Bulb::getListType(int devId) const {
    return new BulbListItem(devId);
}
