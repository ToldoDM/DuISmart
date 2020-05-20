#include "listdevice.h"

ListDevice::ListDevice(){
}

ListDevice::~ListDevice() = default;

DeviceListItem* ListDevice::getListType() const{
    throw new NotImplException("Questa funzione non e' stata implementata");
}
