#include "devicelistitem.h"

DeviceListItem::DeviceListItem(QWidget *parent) : QWidget(parent) {

    //Creazione layout default
    hlay = new QHBoxLayout(this);
    center = new QWidget(this);
    vlay = new QVBoxLayout(center);
    ico = new QLabel(this);

    //Impostazione nomi label
    deviceName = new QLabel(("Interruttore"));
    friendlyName = new QLabel(("Luce cucina"));

    //Impostazione icona default
    ico->setPixmap(QPixmap(":Images/image.jpg").scaled(120,80));
    ico->show();

    vlay->addWidget(deviceName);
    vlay->addWidget(friendlyName);

    hlay->addWidget(ico);
    hlay->addWidget(center);
}
