#ifndef DEVICELISTITEM_H
#define DEVICELISTITEM_H

#include <QBoxLayout>
#include <QLabel>
#include "settingsbutton.h"
#include "Enums/devicetype.h"

class DeviceListItem : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief DeviceListItem: Costruttore di default
     * @param devId: Identificativo dello smart device
     * @param parent: Widget genitore
     */
    explicit DeviceListItem(int devId, const QString& fName, QWidget *parent = nullptr);

    /**
     * @brief ~DeviceListItem: Distruttore
     */
    virtual ~DeviceListItem();

signals:
    /**
     * @brief SettingPressed: Evento generato quando viene premuto il pulsante settings
     * @param devId: Id device di riferimento a cui e' stata chiesta la visualizzazione delle impostazioni
     */
    void SettingPressed(int devId);

protected slots:
    /**
     * @brief onSettingClicked: Cattura evento setting cliecked
     */
    virtual void onSettingClicked()=0;

protected:
    /**
     * @brief settButton: Bottone settings
     */
    SettingsButton *settButton;

    /**
     * @brief deviceName: Nome device (Lampada, TV, Termostato etc.)
     */
    QLabel *deviceName;

    /**
     * @brief friendlyName: Nome assegnato dall'utente
     */
    QLabel *friendlyName;

    /**
     * @brief ico: Label utilizzata per l'icona
     */
    QLabel *ico;

    /**
     * @brief center: Widget utilizzato per arragiare le due label centrali
     */
    QWidget *center;

    /**
     * @brief hlay: Layout principale orizzontale
     */
    QHBoxLayout *hlay;

    /**
     * @brief vlay: Layout verticale utilizzato per il Widget centrale
     */
    QVBoxLayout *vlay;

    /**
     * @brief centerHlay: Layout orizzontale utilizzato per il Widget centrale
     */
    QHBoxLayout *centerHlay;

private:

    /**
     * @brief deviceId: Identificativo del device
     */
    int deviceId;
};

#endif // DEVICELISTITEM_H
