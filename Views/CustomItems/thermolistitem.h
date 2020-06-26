#ifndef THERMOLISTITEM_H
#define THERMOLISTITEM_H

#include "devicelistitem.h"
#include "onoffbutton.h"
#include "Views/thermostatsettings.h"

class ThermoListItem : public DeviceListItem
{
public:
    /**
     * @brief BulbListItem: Costruttore di default
     * @param devId: Identificativo dello smart device
     * @param parent: Widget genitore
     */
    explicit ThermoListItem(int devId, const QString& fName, QWidget *parent = nullptr);

    /**
     * @brief ~BulbListItem: Distruttore
     */
    virtual ~ThermoListItem() override;

    /**
     * @brief getSettingDialog: Ritorna l'oggetto QDialog appartenente ap proprio tipo
     * @return
     */
    ThermostatSettings* getSettingDialog() override;

protected slots:
    /**
     * @brief onSettingClicked: Cattura evento setting cliecked
     */
    virtual void onSettingClicked() override;

private:
    /**
     * @brief interr: Bottone con funzione di interruttore per la lampadina
     */
    OnOffButton *interr;

};

#endif // THERMOLISTITEM_H
