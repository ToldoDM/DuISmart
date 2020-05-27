#include "bulb.h"

Bulb::Bulb(){}

DeviceListItem* Bulb::getListType(int devId) const {
    return new BulbListItem(devId);
}
