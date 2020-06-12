#include "bulblistitem.h"

BulbListItem::BulbListItem(int devId, const QString& fName, QWidget *parent) : DeviceListItem(devId, fName, parent){
    //Impostazione icona bulb
    ico->setPixmap(QPixmap(":Images/bulb.png").scaled(80,80));
    deviceName->setText(tr("Interruttore"));

    interr = new OnOffButton();
    interr->setOnOffIcons(tr(":Images/on.png"), tr(":Images/off.png"), tr(":Images/on_clicked.png"), tr(":Images/off_clicked.png"));

    //Inserimento dello switch acceso/spento
    hlay->addWidget(interr);
}

BulbListItem::~BulbListItem(){
    delete(interr);
}

void BulbListItem::onSettingClicked(){
    emit DeviceListItem::SettingPressed(BULB,deviceId);
}
