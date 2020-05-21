#include "bulblistitem.h"

BulbListItem::BulbListItem(QWidget *parent) : DeviceListItem(parent){

    //Impostazione icona bulb
    ico->setPixmap(QPixmap(":Images/image.jpg").scaled(120,80));

    interr = new OnOffButton();

    //Inserimento dello switch acceso/spento
    hlay->addWidget(interr);
}
