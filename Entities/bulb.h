#ifndef BULB_H
#define BULB_H

#include "listdevice.h"
#include "smartdevice.h"
#include "Views/CustomItems/bulblistitem.h"

class Bulb : public SmartDevice, public ListDevice
{

public:
    /**
     * @brief Bulb: Costruttore di default
     */
    Bulb();

    /**
     * @brief getListType: Metodo utilizzato per creare l'oggetto che verra' visualizzato nella lista dei device.
     * @return Oggetto visivo della lista
     */
    virtual BulbListItem* getListType() const;
};

#endif // BULB_H
