#include "smartdevice.h"

SmartDevice::SmartDevice(const int& devID, const QString& fName) : deviceId(devID), friendlyName(fName) {}

SmartDevice::~SmartDevice() = default;
