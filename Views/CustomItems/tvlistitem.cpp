#include "tvlistitem.h"

TvListItem::TvListItem(int devId, const QString& fName, QWidget *parent) : DeviceListItem(devId, fName, parent){

    //Impostazione icona tv
    ico->setPixmap(QPixmap(":Images/tv.png").scaled(80,80));
    deviceName->setText(tr("TV"));

    interr = new OnOffButton();
    interr->setOnOffIcons(tr(":Images/on.png"), tr(":Images/off.png"), tr(":Images/on_clicked.png"), tr(":Images/off_clicked.png"));

    //Aggiunta scritta con riferimento allo stato attuale del device
    //change = new QLabel("Ch.: 6");
    //centerHlay->addWidget(channel);

    //Inserimento dello switch acceso/spento
    hlay->addWidget(interr);

    //inserimento della label nel layout di devicelistitem
    centerHlay->addWidget(changeChan);

    changeChan->setText("Canale: ");
}

TvListItem::~TvListItem(){
    delete interr;
    delete DeviceListItem::changeChan;
}

void TvListItem::onSettingClicked(){
    emit DeviceListItem::SettingPressed(TV,deviceId);
}
