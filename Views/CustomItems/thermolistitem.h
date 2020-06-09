#ifndef THERMOLISTITEM_H
#define THERMOLISTITEM_H

#include<QString>
#include<QWidget>
#include "devicelistitem.h"

class ThermoListItem : public DeviceListItem
{
public:
    /**
     * @brief BulbListItem: Costruttore di default
     * @param devId: Identificativo dello smart device
     * @param parent: Widget genitore
     */
    explicit ThermoListItem(int devId, const QString& fName, QWidget *parent = nullptr);

    /**
     * @brief ~BulbListItem: Distruttore
     */
    virtual ~ThermoListItem();
};

#endif // THERMOLISTITEM_H
