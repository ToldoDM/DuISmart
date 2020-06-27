#ifndef DEVICESETTINGS_H
#define DEVICESETTINGS_H


#include <QDialog>
#include <QDialogButtonBox>
#include <QGridLayout>
#include "Entities/settingdata.h"


class DeviceSettings: public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Settings: Costruttore di default
     */
    explicit DeviceSettings();

    /**
     * @brief ~DeviceSettings: Distruttore
     */
    virtual ~DeviceSettings();

    /**
     * @brief setCurrentSettings: Imposta i dati correnti all'apertura della finestra
     */
    virtual void setCurrentSettings(const SettingData&) = 0;

signals:

    /**
     * @brief onSetNewSettings: segnale emesso che permette di cambiare le impostazioni
     */
    void onSetNewSettings(const SettingData&) const;


protected slots:

    /**
     * @brief setSettings: Slot utilizzato per gestire le modifiche da parte della finestra settings
     */
    virtual void setSettings() const = 0;

protected:

    /**
     * @brief idDevice: Id device a cui e' associato
     */
    int idDevice;

    /**
     * @brief gLayout: Layout principale finestra setting
     */
    QGridLayout * gLayout;

};

#endif // SETTINGS_H
