#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <QString>
#include <QObject>
#include "settingdata.h"

class SmartDevice : public QObject{
Q_OBJECT
public:
    /**
     * @brief SmartDevice: Costruttore di default
     * @param devID: Id device
     */
    explicit SmartDevice(const int& devID, const QString& fName);

    /**
     * @brief ~SmartDevice: Distruttore virtuale puro
     */
    virtual ~SmartDevice() = 0;

    /**
     * @brief isThisDevice: Metodo che ritorna true se l'id passato come argomento corrisponde all'oggetto stesso
     * @param id: id da verificare
     * @return
     */
    virtual const SmartDevice* isThisDevice(int id) const;

    /**
     * @brief switchOnDevice: Metodo usato per avviare la procedura di accensione del device
     */
    virtual void switchOnDevice() const = 0;

    /**
     * @brief switchOffDevice: Metodo usato per avviare la procedura di spegnimento del device
     */
    virtual void switchOffDevice() const = 0;

    /**
     * @brief setSettings: Imposta il corrente device con le impostazioni date
     * @param data: Dati correnti
     */
    virtual void setSettings(const SettingData& data) = 0;

    /**
     * @brief getSettings: Ottiene le impostazioni correnti del device
     */
    virtual SettingData* getSettings() const = 0;

public slots:

    /**
     * @brief onSetDeviceState: Imposta cosa deve
     */
    virtual void onSetDeviceState(bool);

protected:

    /**
     * @brief deviceId: Identificativo del device
     */
    int deviceId;

    /**
     * @brief friendlyName: Friendly name del device
     */
    QString friendlyName;
};

#endif // SMARTDEVICE_H
