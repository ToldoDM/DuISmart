#include "tvlistitem.h"

TvListItem::TvListItem(int devId, const QString& fName, QWidget *parent) : DeviceListItem(devId, fName, parent){

    //Impostazione icona tv
    ico->setPixmap(QPixmap(":Images/tv.png").scaled(80,80));
    deviceName->setText(tr("TV"));

    interr = new OnOffButton();
    interr->setOnOffIcons(tr(":Images/on.png"), tr(":Images/off.png"), tr(":Images/on_clicked.png"), tr(":Images/off_clicked.png"));

    //Aggiunta scritta con riferimento allo stato attuale del device
    changeChan=new QLabel("");

    //Inserimento dello switch acceso/spento
    hlay->addWidget(interr);

    //inserimento della label nel layout di devicelistitem
    centerHlay->addWidget(changeChan);

    changeChan->setText("");
}

TvListItem::~TvListItem(){
    delete interr;
    delete changeChan;
}

void TvListItem::onSettingClicked(){
    emit SettingPressed(this);
}

TvSettings* TvListItem::getSettingDialog(const SettingData& data){
    TvSettings* ts = new TvSettings(deviceId);
    ts->setCurrentSettings(data);
    return ts;
}

void TvListItem::setSettings(const SettingData& data){
    changeChan->setText("Canale: " + QString::number(data.channel));
}
