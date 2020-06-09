#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "listdevice.h"
#include "smartdevice.h"
#include "Views/CustomItems/thermolistitem.h"

class Thermostat: public SmartDevice, public ListDevice
{

public:
    /**
     * @brief Bulb: Costruttore di default
     * @param devID: Id device
     * @param fName: Friendly name device
     */
    explicit Thermostat(const int& devID, const QString& fName);

    /**
     * @brief getListType: Metodo utilizzato per creare l'oggetto che verra' visualizzato nella lista dei device.
     * @param devId: Id device di riferimento
     * @return Oggetto visivo della lista
     */
    virtual DeviceListItem * getListType() const override;
};

#endif // THERMOSTAT_H
