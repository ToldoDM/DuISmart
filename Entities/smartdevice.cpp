#include "smartdevice.h"

SmartDevice::SmartDevice(const int& devID, const QString& fName) : deviceId(devID), friendlyName(fName) {}

SmartDevice::~SmartDevice() = default;

const SmartDevice* SmartDevice::isThisDevice(int id) const{ return deviceId == id ? this : nullptr; }

void SmartDevice::switchOnDevice() const {}

void SmartDevice::switchOffDevice() const {}
