#ifndef THERMOSTATSETTINGS_H
#define THERMOSTATSETTINGS_H

#include "devicesettings.h"
#include <QLCDNumber>
#include <QPushButton>
#include <QIcon>

class ThermostatSettings : public DeviceSettings
{
    Q_OBJECT
public:
    ThermostatSettings(int idDevice);

    ~ThermostatSettings();

    /**
     * @brief setCurrentSettings: Imposta i dati correnti all'apertura della finestra
     */
    virtual void setCurrentSettings(const SettingData&) override;

    /**
     * @brief BulbSettings: costruttore di copia
     */
    ThermostatSettings(const ThermostatSettings&);

    /**
     * @brief operator =: Operatore di assegnazione
     * @return
     */
    ThermostatSettings& operator=(const ThermostatSettings&);

protected:
    QPushButton *increase;
    QPushButton *decrease;
    QLCDNumber *num ;
    QHBoxLayout *hlay;
    QVBoxLayout *vlay;

private slots:

    /**
     * @brief decrese: Slot gestione diminuzione temperatura
     */
    void decrese();

    /**
     * @brief increse: Slot gestione incremento temperatura
     */
    void increse();

protected slots:

    /**
     * @brief setSettings: Slot utilizzato per gestire le modifiche da parte della finestra settings
     */
    virtual void setSettings() const override;

};

#endif // THERMOSTATSETTINGS_H
