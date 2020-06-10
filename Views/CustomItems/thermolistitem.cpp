#include "thermolistitem.h"

ThermoListItem::ThermoListItem(int devId, const QString& fName, QWidget *parent) : DeviceListItem(devId, fName, parent){

    //Impostazione icona thermostat
    ico->setPixmap(QPixmap(":Images/thermostat.png").scaled(80,80));
    deviceName->setText(tr("Termostato"));

    //Aggiunta bottone on/off con icone custom
    interr = new OnOffButton(DeviceState::On);
    interr->setOnOffIcons(tr(":Images/day.png"), tr(":Images/night.png"), tr(":Images/day_over.png"), tr(":Images/night_over.png"));
    interr->setIconSize(QSize(100,70));

    //Inserimento dello switch day/night
    hlay->addWidget(interr);

}

ThermoListItem::~ThermoListItem(){
    delete(interr);
}
