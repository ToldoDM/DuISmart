#ifndef DEVICELISTITEM_H
#define DEVICELISTITEM_H

#include <QBoxLayout>
#include <QLabel>
#include "settingsbutton.h"
#include "closebutton.h"
#include "Enums/devicetype.h"
#include <QListWidgetItem>
#include "Entities/settingdata.h"
#include "Enums/devicestate.h"

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
     * @brief DeviceListItem: Costruttore di copia
     * @param dli
     */
    DeviceListItem(const DeviceListItem& dli);

    /**
     * @brief operator =: Operatore di assegnazione
     * @return
     */
    DeviceListItem& operator=(const DeviceListItem&);

    /**
     * @brief ~DeviceListItem: Distruttore
     */
    virtual ~DeviceListItem();

    /**
     * @brief setListItem: Imposta il ListItem a cui viene associato il dli
     * @param qli: List item
     */
    void setListItem(QListWidgetItem* qli);

    /**
     * @brief getSettingDialog: Ritorna l'oggetto QDialog appartenente ap proprio tipo
     * @return
     */
    virtual QDialog* getSettingDialog(const SettingData&) = 0;

    /**
     * @brief getDeviceID: Ritorna il device id associato a deviceListItem
     */
    int getDeviceID() const;

    /**
     * @brief getListItem: Ritorna il QListWidgetItem associato
     * @return
     */
    QListWidgetItem* getListItem() const;

public slots:

    /**
     * @brief setSettings: Imposta le settings del device
     * @param data: Settings data
     */
    virtual void setSettings(const SettingData& data) = 0;

signals:
    /**
     * @brief SettingPressed: Evento generato quando viene premuto il pulsante settings
     * @param devId: Id device di riferimento a cui e' stata chiesta la visualizzazione delle impostazioni
     */
    void SettingPressed(DeviceListItem*);

    /**
     * @brief deleteRequest: Evento generato alla richiesta di cancellazione dello smartDevice
     */
    void deleteRequest(QListWidgetItem*, int);

    /**
     * @brief setDeviceOn: Segnale emesso quando viene detto al device di accendersi
     */
    void setDeviceOn(bool);

protected slots:

    /**
     * @brief onOffButtonPressed: Slot utilizzato per gestire l'accensione/spegnimento del device
     */
    virtual void onOffButtonPressed(DeviceState);

    /**
     * @brief onSettingClicked: Cattura evento setting cliecked
     */
    virtual void onSettingClicked();

    /**
     * @brief onDeleteRequest: Slot utilizzato  per rilanciare il segnale deleteRequest con i campi necessari
     */
    void onDeleteRequest();


protected:
    /**
     * @brief settButton: Bottone settings
     */
    SettingsButton *settButton;

    /**
     * @brief closeButton: bottone chiusura
     */
    CloseButton *closeButton;

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

    /**
     * @brief deviceId: Identificativo del device
     */
    int deviceId;

    /**
     * @brief item: Item di riferimento a cui e' attaccato il widget
     */
    QListWidgetItem *item;

};

#endif // DEVICELISTITEM_H
