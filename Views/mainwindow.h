#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPushButton>
#include <QListWidget>
#include <QTabWidget>
#include <QFile>
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
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief setWindowStyle: Imposta lo stile dei vari componenti tramite il file style.css
     */
    void setWindowStyle();

    /**
     * @brief addToAllTab: Aggiunge l'oggetto nel tab di tutti i dispositivi
     */
    void addToAllTab(DeviceListItem* dli) const;

signals:    
    /**
     * @brief addNewDevice: Evento generato quando viene premuto il pulsante aggiungi
     */
    void addNewDevice();

public slots:

private:

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
