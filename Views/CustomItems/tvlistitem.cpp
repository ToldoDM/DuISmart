#include "tvlistitem.h"

TvListItem::TvListItem(int devId, const QString& fName, QWidget *parent) : DeviceListItem(devId, fName, parent){

    //Impostazione icona tv
    ico->setPixmap(QPixmap(":Images/tv.png").scaled(80,80));
    deviceName->setText(tr("TV"));

    interr = new OnOffButton();
    interr->setOnOffIcons(tr(":Images/on.png"), tr(":Images/off.png"), tr(":Images/on_clicked.png"), tr(":Images/off_clicked.png"));
    connect(interr, SIGNAL(onChangeState(DeviceState)), this, SLOT(onOffButtonPressed(DeviceState)));

    //Aggiunta scritta con riferimento allo stato attuale del device
    changeChan=new QLabel("");

    //Inserimento dello switch acceso/spento
    hlay->addWidget(interr);

    //inserimento della label nel layout di devicelistitem
    centerHlay->addWidget(changeChan);

    changeChan->setText("");
}

TvListItem::TvListItem(const TvListItem& tvli) : DeviceListItem(tvli){

    interr = new OnOffButton(*tvli.interr);
    connect(interr, SIGNAL(onChangeState(DeviceState)), this, SLOT(onOffButtonPressed(DeviceState)));

    //Aggiunta scritta con riferimento allo stato attuale del device
    changeChan=new QLabel(tvli.changeChan->text());

    //Inserimento dello switch acceso/spento
    hlay->addWidget(interr);

    //inserimento della label nel layout di devicelistitem
    centerHlay->addWidget(changeChan);
}

TvListItem& TvListItem::operator=(const TvListItem &tvli){
    DeviceListItem::operator=(tvli);
    if(this != &tvli){

        delete interr;
        delete changeChan;

        interr = new OnOffButton(*tvli.interr);
        connect(interr, SIGNAL(onChangeState(DeviceState)), this, SLOT(onOffButtonPressed(DeviceState)));

        //Aggiunta scritta con riferimento allo stato attuale del device
        changeChan=new QLabel(tvli.changeChan->text());

        //Inserimento dello switch acceso/spento
        hlay->addWidget(interr);

        //inserimento della label nel layout di devicelistitem
        centerHlay->addWidget(changeChan);
    }
    return *this;
}

TvListItem::~TvListItem(){
    delete interr;
    delete changeChan;
}

TvSettings* TvListItem::getSettingDialog(const SettingData& data){
    TvSettings* ts = new TvSettings(deviceId);
    ts->setCurrentSettings(data);
    return ts;
}

void TvListItem::setSettings(const SettingData& data){
    changeChan->setText("Canale: " + QString::number(data.channel));
}
