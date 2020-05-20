#ifndef DEVICELISTITEM_H
#define DEVICELISTITEM_H

#include <QBoxLayout>
#include <QLabel>

class DeviceListItem : public QWidget
{

public:
    /**
     * @brief DeviceListItem: Costruttore di default
     * @param parent: Widget genitore
     */
    DeviceListItem(QWidget *parent = nullptr);

protected:
    /**
     * @brief deviceName: Nome device (Lampada, TV, Termostato etc.)
     * @brief friendlyName: Nome assegnato dall'utente
     * @brief ico: Label utilizzata per l'icona
     */
    QLabel *deviceName, *friendlyName, *ico;

    /**
     * @brief center: Widget utilizzato per arragiare le due label centrali
     */
    QWidget *center;

    /**
     * @brief hlay: Layout principale orizzontale
     */
    QHBoxLayout *hlay;

    /**
     * @brief vlay: Layout verticale utilizzato per il Widget centrale
     */
    QVBoxLayout *vlay;
};

#endif // DEVICELISTITEM_H
