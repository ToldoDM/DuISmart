#include "devicelistitem.h"

DeviceListItem::DeviceListItem(int devId, QWidget *parent) : QWidget(parent), deviceId(devId) {

    //Creazione layout default
    hlay = new QHBoxLayout(this);
    center = new QWidget(this);
    vlay = new QVBoxLayout(center);
    ico = new QLabel(this);
    settButton = new SettingsButton(this);

    //Impostazione nomi label
    deviceName = new QLabel(("Interruttore"));
    friendlyName = new QLabel(("Luce cucina"));

    //Impostazione icona default
    ico->setPixmap(QPixmap(":/Images/image.png").scaled(120,80));
    ico->setFixedWidth(120);

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
    delete(center);
    delete(ico);
    delete(hlay);
}

void DeviceListItem::onSettingClicked(){
    //rilancio l'evento indicando a quale device fa' riferimento
    emit SettingPressed(deviceId);
}
