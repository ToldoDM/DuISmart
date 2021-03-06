#include "devicelistitem.h"

DeviceListItem::DeviceListItem(int devId, const QString& fName, QWidget *parent) : QWidget(parent), deviceId(devId) {

    //Creazione layout default
    hlay = new QHBoxLayout(this);
    center = new QWidget(this);
    centerHlay = new QHBoxLayout(center);
    vlay = new QVBoxLayout();
    ico = new QLabel(this);
    settButton = new SettingsButton(this);

    closeButton= new CloseButton(this);

    //Impostazione nomi label
    deviceName = new QLabel();
    friendlyName = new QLabel(fName);

    //Impostazione icona default
    ico->setPixmap(QPixmap(":/Images/image.png").scaled(120,80));
    ico->setFixedWidth(120);

    //Widget centrale
    centerHlay->addLayout(vlay);
    vlay->addWidget(deviceName);
    vlay->addWidget(friendlyName);

    //prova posizione bottone chiusura
    hlay->addWidget(closeButton);

    hlay->addWidget(ico);
    hlay->addWidget(center);
    hlay->addWidget(settButton);


    //connessione segnali e slot
    connect(settButton,SIGNAL(onClicked()),this,SLOT(onSettingClicked()));
    connect(closeButton,SIGNAL(onClicked()),this,SLOT(onDeleteRequest()));
}

void DeviceListItem::onOffButtonPressed(DeviceState state){
    emit setDeviceOn(state == DeviceState::On);
}

void DeviceListItem::onSettingClicked(){
    emit SettingPressed(this);
}

DeviceListItem::DeviceListItem(const DeviceListItem& dli){
    deviceId = dli.deviceId;

    //Creazione layout default
    hlay = new QHBoxLayout(this);
    center = new QWidget(this);
    centerHlay = new QHBoxLayout(center);
    vlay = new QVBoxLayout();
    settButton = new SettingsButton(*dli.settButton);
    ico = new QLabel(this);
    ico->setPixmap(*ico->pixmap());

    closeButton= new CloseButton(*dli.closeButton);

    //Impostazione nomi label
    deviceName = new QLabel(dli.deviceName->text());
    friendlyName = new QLabel(dli.friendlyName->text());

    //Impostazione icona default
    ico->setFixedWidth(120);

    //Widget centrale
    centerHlay->addLayout(vlay);
    vlay->addWidget(deviceName);
    vlay->addWidget(friendlyName);

    hlay->addWidget(closeButton);

    hlay->addWidget(ico);
    hlay->addWidget(center);
    hlay->addWidget(settButton);

    //connessione segnali e slot
    connect(settButton,SIGNAL(onClicked()),this,SLOT(onSettingClicked()));
    connect(closeButton,SIGNAL(onClicked()),this,SLOT(onDeleteRequest()));
}

DeviceListItem& DeviceListItem::operator=(const DeviceListItem& dli){
    if(&dli != this){
        delete(closeButton);
        delete(settButton);
        delete(friendlyName);
        delete(deviceName);
        delete(ico);

        deviceId = dli.deviceId;
        settButton = new SettingsButton(*dli.settButton);
        ico = new QLabel(this);
        ico->setPixmap(*ico->pixmap());
        closeButton= new CloseButton(*dli.closeButton);
        deviceName = new QLabel(dli.deviceName->text());
        friendlyName = new QLabel(dli.friendlyName->text());
        ico->setFixedWidth(120);

        //Widget centrale
        centerHlay->addLayout(vlay);
        vlay->addWidget(deviceName);
        vlay->addWidget(friendlyName);

        hlay->addWidget(closeButton);

        hlay->addWidget(ico);
        hlay->addWidget(center);
        hlay->addWidget(settButton);

        //connessione segnali e slot
        connect(settButton,SIGNAL(onClicked()),this,SLOT(onSettingClicked()));
        connect(closeButton,SIGNAL(onClicked()),this,SLOT(onDeleteRequest()));
    }
    return *this;
}

void DeviceListItem::onDeleteRequest(){ emit deleteRequest(item, deviceId); }


void DeviceListItem::setListItem(QListWidgetItem *qli){ item = qli; }


int DeviceListItem::getDeviceID() const { return deviceId; }

QListWidgetItem* DeviceListItem::getListItem() const { return item; }


DeviceListItem::~DeviceListItem(){
    delete(closeButton);
    delete(settButton);
    delete(friendlyName);
    delete(deviceName);
    delete(vlay);
    delete(centerHlay);
    delete(center);
    delete(ico);
    delete(hlay);
}

