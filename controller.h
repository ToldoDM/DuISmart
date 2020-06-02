#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "Models/mainviewmodel.h"
#include "Models/additemmodel.h"
#include "Views/mainwindow.h"
#include "Views/additemwindow.h"

class Controller : public QObject {
    Q_OBJECT


signals:

private slots:
    /**
     * @brief clieckedHandler: Slot utilizzato per catturare il segnale bottone premuto di addDevice
     */
    void riseAddWindow();

    /**
     * @brief addNewDeviceToMainW: Slot utilizzato per aggiungere il device alla mainW
     */
    void addNewDeviceToMainW() const;

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

private:

    /**
     * @brief secondaFinestra: Puntatore creato per passare la finestra parent alla finestra additem
     */
    QDialog* secondaFinestra;
    /**
     * @brief AddItemW: Finestra aggiunta nuovo device
     */
    AddItemWindow* AddItemW;
    /**
     * @brief AddItemVM: Model Finestra aggiunta nuovo device
     */
    AddItemModel* AddItemVM;

    /**
     * @brief MainVM: model della MainWindow
     */
    MainViewModel* MainVM;
    /**
     * @brief MainW: Finestra principale
     */
    MainWindow* MainW;

    /**
     * @brief addSmartDeviceToList: aggiunge lo smartDevice alla lista della main window
     */
    void addSmartDeviceToList(SmartDevice* device) const;

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
