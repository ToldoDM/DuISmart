#ifndef DEVICETYPE_H
#define DEVICETYPE_H

#include <QMetaType>

enum DeviceType{
    BULB = 0,
    TV =1,
    THERMOSTAT =2,
};
Q_DECLARE_METATYPE(DeviceType)

#endif // DEVICETYPE_H
