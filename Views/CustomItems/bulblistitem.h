#ifndef BULBLISTITEM_H
#define BULBLISTITEM_H

#include "devicelistitem.h"
#include <QPushButton>

class BulbListItem : public DeviceListItem
{
public:

    /**
     * @brief BulbListItem: Costruttore di default
     * @param parent: Widget genitore
     */
    BulbListItem(QWidget *parent = nullptr);

private:
    /**
     * @brief interr: Bottone con funzione di interruttore per la lampadina
     */
    QPushButton *interr;
};

#endif // BULBLISTITEM_H
