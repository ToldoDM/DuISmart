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

private:
    int contrast;
    int brightness;
    int channel;
};

#endif // TV_H
