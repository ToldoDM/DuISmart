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
     * @param fName: Friendly name device
     */
    explicit Bulb(const int& devID, const QString& fName);

    /**
     * @brief getListType: Metodo utilizzato per creare l'oggetto che verra' visualizzato nella lista dei device.
     * @param devId: Id device di riferimento
     * @return Oggetto visivo della lista
     */
    virtual DeviceListItem * getListType() const override;    

    /**
     * @brief switchOnDevice: Metodo usato per avviare la procedura di accensione del device
     */
    virtual void switchOnDevice() const override;

    /**
     * @brief switchOffDevice: Metodo usato per avviare la procedura di spegnimento del device
     */
    virtual void switchOffDevice() const override;

    /**
     * @brief setSettings: Imposta il corrente device con le impostazioni date
     * @param data: Dati correnti
     */
    virtual void setSettings(const SettingData &data) override;

    /**
     * @brief getSettings: Ottiene le impostazioni correnti del device
     */
    virtual SettingData* getSettings() const override;

private:
    int brightness = 0;
    int red = 255;
    int blue = 255;
    int green = 255;
};

#endif // BULB_H
