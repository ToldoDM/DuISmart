#include "devicelistitem.h"

DeviceListItem::DeviceListItem(int devId, const QString& fName, QWidget *parent) : QWidget(parent), deviceId(devId) {

    //Creazione layout default
    hlay = new QHBoxLayout(this);
    center = new QWidget(this);
    centerHlay = new QHBoxLayout(center);
    vlay = new QVBoxLayout();
    ico = new QLabel(this);
    settButton = new SettingsButton(this);

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

    hlay->addWidget(ico);
    hlay->addWidget(center);
    hlay->addWidget(settButton);

    //connessione segnali e slot
    connect(settButton,SIGNAL(onClicked()),this,SLOT(onSettingClicked()));
}

DeviceListItem::~DeviceListItem(){
    delete(settButton);
    delete(friendlyName);
    delete(deviceName);
    delete(vlay);
    delete(centerHlay);
    delete(center);
    delete(ico);
    delete(hlay);
}

