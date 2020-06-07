#ifndef CONTROLLER_H
#define CONTROLLER_H

#include<QObject>
#include<Models/mainviewmodel.h>
#include<Views/mainwindow.h>

#include "Views/bulbsettings.h"


class Controller : public QObject {
    Q_OBJECT


signals:

private slots:
    /**
     * @brief riseSettingsWindow: slot utilizzato per catturare segnale inviato per accedere alle impostazioni del device bulb
     */
    void riseBulbSettingsWindow();

    /**
     * @brief BulbSelectColor: mostra impostazioni cambio colore/luminosità
     */
    void BulbSelectColor() const;

    /**
     * @brief ChangeToSelectedColor: applica modifiche al bottone
     */
    void ChangeToSelectedColor(const QColor) const;

    /**
     * @brief getBulbSettings: prende modifiche lampadina
     */
    void getBulbSettings(const QColor, const int);

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
