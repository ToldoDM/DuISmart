#include "thermolistitem.h"

ThermoListItem::ThermoListItem(int devId, const QString& fName, QWidget *parent) : DeviceListItem(devId, fName, parent){

    //Impostazione icona thermostat
    ico->setPixmap(QPixmap(":Images/thermostat.png").scaled(80,80));
    deviceName->setText(tr("Termostato"));

    //Aggiunta bottone on/off con icone custom
    interr = new OnOffButton(DeviceState::On);
    interr->setOnOffIcons(tr(":Images/day.png"), tr(":Images/night.png"), tr(":Images/day_over.png"), tr(":Images/night_over.png"));
    interr->setIconSize(QSize(100,70));

    //Aggiunta scritta con riferimento allo stato attuale del device
    //change = new QLabel("23°C");
    //centerHlay->addWidget(change);

    //Inserimento dello switch day/night
    hlay->addWidget(interr);

    //inserimento qlabel nel layout di devicelistitem
    centerHlay->addWidget(changeTemp);

    changeTemp->setText("Temperatura: ");
}

ThermoListItem::~ThermoListItem(){
    delete interr;
    delete changeTemp;
}


void ThermoListItem::onSettingClicked(){
    emit DeviceListItem::SettingPressed(THERMOSTAT,deviceId);
}

