#ifndef TV_H
#define TV_H

#include "Views/CustomItems/tvlistitem.h"
#include "smartdevice.h"
#include "listdevice.h"

class Tv : public SmartDevice, public ListDevice
{
public:
    /**
     * @brief Tv: Costruttore di default
     * @param devID: Id nuovo device
     * @param fName: Friendly name device
     */
    explicit Tv(const int& devID, const QString& fName);

    /**
     * @brief getListType: Metodo utilizzato per creare l'oggetto che verra' visualizzato nella lista dei device.
     * @param devId: Id device di riferimento
     * @return Oggetto visivo della lista
     */
    virtual DeviceListItem * getListType() const override;
};

#endif // TV_H
