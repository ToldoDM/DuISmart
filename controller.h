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

#include "Views/bulbsettings.h"
#include "Views/displaysettings.h"
#include "Views/thermostatsettings.h"

#include "txtmanager.h"

class Controller : public QObject {
    Q_OBJECT

private slots:
    /**
     * @brief getThermostatSettings: ottiene le modifiche apportate al termostato
     */
    //void getThermostatSettings(int);

    /**
     * @brief getBulbSettings: ottiene modifiche display
     */
    //void getBulbSettings(const QColor , const int);

    /**
     * @brief getDisplaySettings: ottiene modifiche display
     */
    //void getDisplaySettings(const int , const int);

    /**
     * @brief addWinClosed: Slot utilizzato per la distruzione dell'oggetto AddItemWindow
     * @param result: Risultato dialog
     */
    void addWinClosed(int result);

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
     * @brief setDeviceNameChanged: Slot utilizzato per aggironare il valore dalla variabile al model
     * @param text: New Text
     */
    void setDeviceNameChanged(const QString& text) const;

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
     * @param deviceID: codice identificativo unico degli oggetti
     */
    void selectSettings(DeviceType,int deviceID) const;

private:

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
     * @brief addSmartDeviceToList: aggiunge lo smartDevice alla lista della main window
     */
    void addSmartDeviceToList(SmartDevice* device, const QString& targetTab) const;

    mutable BulbSettings *BulbS;

    mutable DisplaySettings *DispS;

    mutable ThermostatSettings *TherS;

    /**
     * @brief fileIO: oggetto che permette scrittura su file
     */
    TxtManager* fileIO;

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
