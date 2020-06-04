#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPushButton>
#include <QListWidget>
#include <QTabWidget>
#include <QFile>
#include "Models/mainviewmodel.h"
#include "CustomItems/bulblistitem.h"


class MainWindow : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief MainWindow: Costruttore di default
     * @param model: Model della vista
     * @param parent: Widget genitore
     */
    explicit MainWindow(MainViewModel* model, QWidget *parent = nullptr);

    /**
     * @brief setWindowStyle: Imposta lo stile dei vari componenti tramite il file style.css
     */
    void setWindowStyle();

    /**
     * @brief addToAllList: Aggiunge l'oggetto alla lista di tutti i dispositivi
     */
    void addToAllList() const;

signals:

public slots:
    /**
     * @brief clieckedHandler: Slot utilizzato per catturare il segnale bottone premuto di addDevice
     */
    void addClieckedHandler();

    /**
     * @brief sett: prova buttone settings
     */
    void sett();

private:
    /**
     * @brief model: Utilizzato per prendere i valori da visualizzare
     */
    MainViewModel* model;

    /**
     * @brief defaultTab: Rappresenta il tab di default contenente la lista di tutti i device
     */
    QListWidget *defaultTab;

    /**
     * @brief addDevice: Pulsante per l'aggiunta di un nuovo device
     */
    QPushButton *addDevice;

    QTabWidget *tab;

    /**
     * @brief secondaFinestra: Puntatore creato per passare la finestra parent alla finestra additem
     */
    QDialog *secondaFinestra;

    //prova finestra impostazioni
    QWidget *prova;

};

#endif // MAINWINDOW_H
