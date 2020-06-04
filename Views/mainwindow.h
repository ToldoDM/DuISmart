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
     * @brief addToAllTab: Aggiunge l'oggetto nel tab di tutti i dispositivi e nel tab stanza scelto
     */
    void addToAllTab(DeviceListItem* dli, const QString& tabName) const;

    /**
     * @brief addTab: Aggiunge un nuovo tab
     * @param tabName: Nome tab da aggiungere
     */
    void addTab(const QString& tabName, bool isAll = false);

signals:    
    /**
     * @brief addNewDevice: Evento generato quando viene premuto il pulsante aggiungi
     */
    void addNewDevice();

public slots:

private:

    /**
     * @brief addDevice: Pulsante per l'aggiunta di un nuovo device
     */
    QPushButton *addDevice;

    /**
     * @brief tab: Tab contenente le varie stanze
     */
    QTabWidget *tab;

};

#endif // MAINWINDOW_H
