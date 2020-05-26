#include "bulb.h"

Bulb::Bulb(){}

DeviceListItem* Bulb::getListType() const {
    return new BulbListItem();
}
