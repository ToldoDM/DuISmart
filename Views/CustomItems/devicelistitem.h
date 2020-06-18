#ifndef DEVICELISTITEM_H
#define DEVICELISTITEM_H

#include <QSize>
#include <QBoxLayout>
#include <QLabel>
#include "settingsbutton.h"
#include "closebutton.h"
#include "Enums/devicetype.h"
#include <QListWidgetItem>

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

    /**
     * @brief setListItem: Imposta il ListItem a cui viene associato il dli
     * @param qli: List item
     */
    void setListItem(QListWidgetItem* qli);

    /**
     * @brief Change: Label che identifica temperatura / canale
     */
    QLabel *changeTemp;
    QLabel *changeChan;

public slots:
    /**
     * @brief changeLabelChan:slot utilizzato per modificare in label canale
     */
    void changeLabelChan(int);

    /**
     * @brief changeLabelTemp:slot utilizzato per modificare in label temperatura
     */
    void changeLabelTemp(int);

signals:
    /**
     * @brief SettingPressed: Evento generato quando viene premuto il pulsante settings
     * @param devId: Id device di riferimento a cui e' stata chiesta la visualizzazione delle impostazioni
     */
    void SettingPressed(DeviceType,int devId);

    /**
     * @brief deleteRequest: Evento generato alla richiesta di cancellazione dello smartDevice
     */
    void deleteRequest(QListWidgetItem*, int);

protected slots:
    /**
     * @brief onSettingClicked: Cattura evento setting cliecked
     */
    virtual void onSettingClicked()=0;

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
