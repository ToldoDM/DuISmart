#include "bulblistitem.h"

BulbListItem::BulbListItem(int devId, const QString& fName, QWidget *parent) : DeviceListItem(devId, fName, parent){
    //Impostazione icona bulb
    ico->setPixmap(QPixmap(":Images/bulb.png").scaled(80,80));
    deviceName->setText(tr("Interruttore"));

    interr = new OnOffButton();
    interr->setOnOffIcons(tr(":Images/on.png"), tr(":Images/off.png"), tr(":Images/on_clicked.png"), tr(":Images/off_clicked.png"));
    connect(interr, SIGNAL(onChangeState(DeviceState)), this, SLOT(onOffButtonPressed(DeviceState)));

    //Inserimento dello switch acceso/spento
    hlay->addWidget(interr);
}

BulbListItem::BulbListItem(const BulbListItem& bli) : DeviceListItem(bli){
    interr = new OnOffButton(*bli.interr);
    connect(interr, SIGNAL(onChangeState(DeviceState)), this, SLOT(onOffButtonPressed(DeviceState)));
}

BulbListItem& BulbListItem::operator=(const BulbListItem &bli){
    DeviceListItem::operator=(bli);
    if(this != &bli){
        delete interr;
        interr = new OnOffButton(*bli.interr);
        connect(interr, SIGNAL(onChangeState(DeviceState)), this, SLOT(onOffButtonPressed(DeviceState)));
    }
    return *this;
}

BulbListItem::~BulbListItem(){
    delete(interr);
}

BulbSettings* BulbListItem::getSettingDialog(const SettingData& data){
    BulbSettings* bs = new BulbSettings(deviceId);
    bs->setCurrentSettings(data);
    return bs;
}

void BulbListItem::setSettings(const SettingData&){}

