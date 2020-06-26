#ifndef TVLISTITEM_H
#define TVLISTITEM_H

#include<QString>
#include<QWidget>
#include "onoffbutton.h"
#include "devicelistitem.h"
#include "Views/tvsettings.h"

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

    /**
     * @brief getSettingDialog: Ritorna l'oggetto QDialog appartenente ap proprio tipo
     * @return
     */
    TvSettings* getSettingDialog() override;

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
};

#endif // TVLISTITEM_H
