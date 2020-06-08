#ifndef ROOMTYPE_H
#define ROOMTYPE_H

#include <QMetaType>

enum RoomType{
    NEW = 0,
    EXIST =1,
};
Q_DECLARE_METATYPE(RoomType)

#endif // ROOMTYPE_H
