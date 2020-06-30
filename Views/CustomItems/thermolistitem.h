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
     * @brief BulbListItem: Costruttore di copia
     */
    ThermoListItem(const ThermoListItem&);

    /**
     * @brief operator=: Operatore di assegnazione
     * @return
     */
    ThermoListItem& operator=(const ThermoListItem&);

    /**
     * @brief getSettingDialog: Ritorna l'oggetto QDialog appartenente ap proprio tipo
     * @return
     */
    ThermostatSettings* getSettingDialog(const SettingData&) override;

public slots:

    /**
     * @brief setSettings: Imposta le settings del device
     * @param data: Settings data
     */
    virtual void setSettings(const SettingData& data) override;

protected slots:
    /**
     * @brief onSettingClicked: Cattura evento setting cliecked
     */
    virtual void onSettingClicked() override;

private:

    /**
     * @brief Change: Label che identifica temperatura / canale
     */
    QLabel *changeTemp;

    /**
     * @brief interr: Bottone con funzione di interruttore per la lampadina
     */
    OnOffButton *interr;

};

#endif // THERMOLISTITEM_H
