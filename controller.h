#ifndef CONTROLLER_H
#define CONTROLLER_H

#include<QObject>
#include<Models/mainviewmodel.h>
#include<Views/mainwindow.h>

#include "Views/bulbsettings.h"
#include "Views/displaysettings.h"
#include "Views/thermostatsettings.h"

class Controller : public QObject {
    Q_OBJECT


signals:

private slots:
    /**
     * @brief riseSettingsWindow: slot utilizzato per catturare segnale inviato per accedere alle impostazioni del device bulb
     */
    void riseBulbSettingsWindow();

    /**
     * @brief riseDisplaySettings: stessa cosa del precedente ma di display settings
     */
    void riseDisplaySettings();

    /**
     * @brief getDisplaySettings: ottiene modifiche display
     */
    void getBulbSettings(const QColor , const int);

    /**
     * @brief getDisplaySettings: ottiene modifiche display
     */
    void getDisplaySettings(const int , const int);

private:

    /**
     * @brief MainVM: model della MainWindow
     */
    MainViewModel* MainVM;
    /**
     * @brief MainW: Finestra principale
     */
    MainWindow* MainW;

    BulbSettings *BulbS;

    DisplaySettings *DispS;

    thermostatSettings *TherS;

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
