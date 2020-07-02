#include "thermolistitem.h"

ThermoListItem::ThermoListItem(int devId, const QString& fName, QWidget *parent) : DeviceListItem(devId, fName, parent){


    //Impostazione icona thermostat
    ico->setPixmap(QPixmap(":Images/thermostat.png").scaled(80,80));
    deviceName->setText(tr("Termostato"));

    //Aggiunta bottone on/off con icone custom
    interr = new OnOffButton(DeviceState::On);
    interr->setOnOffIcons(tr(":Images/day.png"), tr(":Images/night.png"), tr(":Images/day_over.png"), tr(":Images/night_over.png"));
    interr->setIconSize(QSize(100,70));
    connect(interr, SIGNAL(onChangeState(DeviceState)), this, SLOT(onOffButtonPressed(DeviceState)));

    //Aggiunta scritta con riferimento allo stato attuale del device
    changeTemp=new QLabel("");

    //Inserimento dello switch day/night
    hlay->addWidget(interr);

    //inserimento qlabel nel layout di devicelistitem
    centerHlay->addWidget(changeTemp);

    changeTemp->setText("");
}

ThermoListItem::ThermoListItem(const ThermoListItem& tli) : DeviceListItem(tli){
    interr = new OnOffButton(*tli.interr);
    connect(interr, SIGNAL(onChangeState(DeviceState)), this, SLOT(onOffButtonPressed(DeviceState)));

    //Aggiunta scritta con riferimento allo stato attuale del device
    changeTemp=new QLabel(tli.changeTemp->text());

    //Inserimento dello switch acceso/spento
    hlay->addWidget(interr);

    //inserimento della label nel layout di devicelistitem
    centerHlay->addWidget(changeTemp);
}

ThermoListItem& ThermoListItem::operator=(const ThermoListItem &tli){
    DeviceListItem::operator=(tli);
    if(this != &tli){

        delete interr;
        delete changeTemp;

        interr = new OnOffButton(*tli.interr);
        connect(interr, SIGNAL(onChangeState(DeviceState)), this, SLOT(onOffButtonPressed(DeviceState)));

        //Aggiunta scritta con riferimento allo stato attuale del device
        changeTemp=new QLabel(tli.changeTemp->text());

        //Inserimento dello switch acceso/spento
        hlay->addWidget(interr);

        //inserimento della label nel layout di devicelistitem
        centerHlay->addWidget(changeTemp);
    }
    return *this;
}

ThermoListItem::~ThermoListItem(){
    delete interr;
    delete changeTemp;
}

ThermostatSettings* ThermoListItem::getSettingDialog(const SettingData& data){
    ThermostatSettings* ts = new ThermostatSettings(deviceId);
    ts->setCurrentSettings(data);
    return ts;
}

void ThermoListItem::setSettings(const SettingData& data){
    changeTemp->setText("Temperatura: " + QString::number(data.temp));
}
