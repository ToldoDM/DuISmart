#ifndef BULBLISTITEM_H
#define BULBLISTITEM_H

#include "devicelistitem.h"
#include "onoffbutton.h"
#include "Views/bulbsettings.h"

class BulbListItem : public DeviceListItem
{
public:

    /**
     * @brief BulbListItem: Costruttore di default
     * @param devId: Identificativo dello smart device
     * @param parent: Widget genitore
     */
    explicit BulbListItem(int devId, const QString& fName, QWidget *parent = nullptr);

    /**
     * @brief ~BulbListItem: Distruttore
     */
    virtual ~BulbListItem() override;

    /**
     * @brief BulbListItem: Costruttore di copia
     */
    BulbListItem(const BulbListItem&);

    /**
     * @brief operator=: Operatore di assegnazione
     * @return
     */
    BulbListItem& operator=(const BulbListItem&);

    /**
     * @brief getSettingDialog: Ritorna l'oggetto QDialog appartenente ap proprio tipo
     * @return
     */
    BulbSettings* getSettingDialog(const SettingData&) override;

public slots:

    /**
     * @brief setSettings: Imposta le settings del device
     * @param data: Settings data
     */
    virtual void setSettings(const SettingData& data) override;

private:
    /**
     * @brief interr: Bottone con funzione di interruttore per la lampadina
     */
    OnOffButton *interr;

};

#endif // BULBLISTITEM_H
