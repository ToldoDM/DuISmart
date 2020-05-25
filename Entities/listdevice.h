#ifndef LISTDEVICE_H
#define LISTDEVICE_H

#include "Views/CustomItems/devicelistitem.h"
#include "Exceptions/notimplexception.h"

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
     * @return Oggetto visivo della lista
     */
    virtual DeviceListItem* getListType() const = 0;

};

#endif // LISTDEVICE_H
