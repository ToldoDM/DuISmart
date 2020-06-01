#ifndef LISTDEVICE_H
#define LISTDEVICE_H

#include "Views/CustomItems/devicelistitem.h"
#include "Exceptions/argumentexception.h"

class ListDevice
{

public:
    /**
     * @brief ListDevice: Costruttore di default
     */
    explicit ListDevice();

    /**
     * @brief ~ListDevice: Distruttore di default
     */
    virtual ~ListDevice() = 0;

    /**
     * @brief getListType: Metodo utilizzato per creare l'oggetto che verra' visualizzato nella lista dei device.
     * ATTENZIONE!!! THROWABLE!!!
     * @param devId: Id device di riferimento
     * @return Oggetto visivo della lista
     */
    virtual DeviceListItem* getListType(int devId) const = 0;

};

#endif // LISTDEVICE_H
