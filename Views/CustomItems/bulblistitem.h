#ifndef BULBLISTITEM_H
#define BULBLISTITEM_H

#include "devicelistitem.h"
#include "onoffbutton.h"

class BulbListItem : public DeviceListItem
{
public:

    /**
     * @brief BulbListItem: Costruttore di default
     * @param parent: Widget genitore
     */
    BulbListItem(QWidget *parent = nullptr);

    /**
     * @brief ~BulbListItem: Distruttore
     */
    virtual ~BulbListItem() override;

private:
    /**
     * @brief interr: Bottone con funzione di interruttore per la lampadina
     */
    OnOffButton *interr;
};

#endif // BULBLISTITEM_H
