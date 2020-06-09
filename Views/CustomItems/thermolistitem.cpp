#include "thermolistitem.h"

ThermoListItem::ThermoListItem(int devId, const QString& fName, QWidget *parent) : DeviceListItem(devId, fName, parent){

    //Impostazione icona bulb
    ico->setPixmap(QPixmap(":Images/thermostat.png").scaled(80,80));
    deviceName->setText(tr("Termostato"));

}

ThermoListItem::~ThermoListItem(){}
