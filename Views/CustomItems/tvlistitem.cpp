#include "tvlistitem.h"

TvListItem::TvListItem(int devId, const QString& fName, QWidget *parent) : DeviceListItem(devId, fName, parent){

    //Impostazione icona bulb
    ico->setPixmap(QPixmap(":Images/tv.png").scaled(80,80));
    deviceName->setText(tr("TV"));

    interr = new OnOffButton();

    //Inserimento dello switch acceso/spento
    hlay->addWidget(interr);
}

TvListItem::~TvListItem(){
    delete(interr);
}
