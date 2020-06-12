#ifndef TVLISTITEM_H
#define TVLISTITEM_H

#include<QString>
#include<QWidget>
#include "onoffbutton.h"
#include "devicelistitem.h"

class TvListItem : public DeviceListItem
{
public:
    /**
     * @brief BulbListItem: Costruttore di default
     * @param devId: Identificativo dello smart device
     * @param parent: Widget genitore
     */
    explicit TvListItem(int devId, const QString& fName, QWidget *parent = nullptr);

    /**
     * @brief ~BulbListItem: Distruttore
     */
    virtual ~TvListItem();

protected slots:
    /**
     * @brief onSettingClicked: Cattura evento setting cliecked
     */
    virtual void onSettingClicked() override;

private:
    /**
     * @brief interr: Bottone con funzione di interruttore per la lampadina
     */
    OnOffButton *interr;

    /**
     * @brief channel: Label che indica il canale attuale della televisione
     */
    QLabel *channel;
};

#endif // TVLISTITEM_H
