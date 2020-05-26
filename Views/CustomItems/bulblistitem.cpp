#include "bulblistitem.h"

BulbListItem::BulbListItem(QWidget *parent) : DeviceListItem(parent){

    //Impostazione icona bulb
    ico->setPixmap(QPixmap(":Images/bulb.png").scaled(80,80));

    interr = new OnOffButton();

    //Inserimento dello switch acceso/spento
    hlay->addWidget(interr);
}

BulbListItem::~BulbListItem(){
    delete(interr);
}
