#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "Models/mainviewmodel.h"
#include "Models/additemmodel.h"
#include "Views/mainwindow.h"
#include "Views/additemwindow.h"
#include "Entities/bulb.h"
#include "Entities/tv.h"
#include "Entities/thermostat.h"
#include <iostream>
#include <exception>
#include <QErrorMessage>

#include "Views/bulbsettings.h"
#include "Views/tvsettings.h"
#include "Views/thermostatsettings.h"

class Controller : public QObject {
    Q_OBJECT

private slots:

    /**
     * @brief addWinClosed: Slot utilizzato per la distruzione dell'oggetto AddItemWindow
     */
    void addWinClosed();

    /**
     * @brief settWinClosed: Slot utilizzato per la distruzione dell'oggetto settW
     */
    void settWinClosed();

    /**
     * @brief clieckedHandler: Slot utilizzato per catturare il segnale bottone premuto di addDevice
     */
    void riseAddWindow();

    /**
     * @brief addNewDeviceToMainW: Slot utilizzato per aggiungere il device alla mainW
     * @param dType: Tipo enum DeviceType
     * @param roomName: Nome stanza in cui inserire il device
     */
    void addNewDeviceToMainW(DeviceType dType, const QString& roomName);

    /**
     * @brief setFriendlyNameChanged: Slot utilizzato per aggironare il valore dalla variabile al model
     * @param text: New Text
     */
    void setFriendlyNameChanged(const QString& text) const;

    /**
     * @brief addNewRoom: Slot utilizzato per aggiungere una stanza alla lista delle stanze
     * @param roomName: Nome nuova stanza
     */
    void addNewRoom(const QString& roomName) const;

    /**
     * @brief selectSettings:: Slot utilizzato per sciegliere quale schermata impostazioni visualizzare per un determinato oggetto
     * @param dli: device list item da cui e' stato premuto il pulsante
     */
    void selectSettings(DeviceListItem* dli);


     /** @brief removeSmartDeviceFromList: rimuove lo smart device dalla lista visiva e dalla lista codice
     */
    void removeSmartDeviceFromList(QListWidgetItem*, int) const;

    /**
     * @brief setSettings: Imposta le settings del device
     * @param data: Settings data
     */
    void setSettings(const SettingData& data);

    /**
     * @brief RemoveRoomFromModel: Rimuove dal MainVM il nome stanza dalla lista drop down
     */
    void removeRoomFromModel(const QString&);

private:

    /**
     * @brief addSmartDeviceToList: aggiunge lo smartDevice alla lista della main window
     */
    DeviceListItem* addSmartDeviceToList(SmartDevice* device, const QString& targetTab) const;

    /**
     * @brief dli:oggetto di tipo device list item
     */
    DeviceListItem *dli;

    /**
     * @brief idCount: Id count utilizzato per gli id univoci dei device
     */
    int idCount = 0;

    /**
     * @brief AddItemW: Finestra aggiunta nuovo device
     */
    AddItemWindow* AddItemW = nullptr;
    /**
     * @brief AddItemVM: Model Finestra aggiunta nuovo device
     */
    AddItemModel* AddItemVM = nullptr;

    /**
     * @brief MainVM: model della MainWindow
     */
    MainViewModel* MainVM = nullptr;
    /**
     * @brief MainW: Finestra principale
     */
    MainWindow* MainW = nullptr;

    /**
     * @brief settW: Dialog setting window
     */
    QDialog *settW;


public:
    /**
     * @brief Controller	costruttore del controller
     * @param parent        widget genitore
     */
    Controller(QObject* parent = nullptr);

    /**
     * @brief ShowMainWindow: Comando che chiama show della mainWindow
     */
    void ShowMainWindow() const;

};

#endif
