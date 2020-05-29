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
     * @brief addToAllTab: Aggiunge l'oggetto nel tab di tutti i dispositivi
     */
    void addToAllTab(DeviceListItem* dli) const;

signals:

public slots:
    /**
     * @brief clieckedHandler: Slot utilizzato per catturare il segnale bottone premuto di addDevice
     */
    void addClieckedHandler();

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



};

#endif // MAINWINDOW_H
