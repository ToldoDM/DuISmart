#include "listdevice.h"

ListDevice::ListDevice(){
}

ListDevice::~ListDevice() = default;

DeviceListItem* ListDevice::getListType() const{
    throw ArgumentException("Questa funzione non e' stata implementata");
}
