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
     * @param devID: Id device
     */
    explicit Bulb(const int& devID);

    /**
     * @brief getListType: Metodo utilizzato per creare l'oggetto che verra' visualizzato nella lista dei device.
     * @param devId: Id device di riferimento
     * @return Oggetto visivo della lista
     */
    virtual DeviceListItem * getListType(int devId) const override;
};

#endif // BULB_H
