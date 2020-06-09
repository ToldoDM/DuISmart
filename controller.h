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

class Controller : public QObject {
    Q_OBJECT

private slots:

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
