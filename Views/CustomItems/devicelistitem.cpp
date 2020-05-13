#include "devicelistitem.h"

DeviceListItem::DeviceListItem(QWidget *parent) : QWidget(parent) {

    hlay = new QHBoxLayout(this);
    button = new QPushButton(tr("bottone"), this);
    ico = new QLabel(this);
    ico->setPixmap(QPixmap(":Images/image.jpg").scaled(120,80));
    ico->show();


    center = new QWidget(this);
    vlay = new QVBoxLayout(center);
    deviceName = new QLabel(("Interruttore"));
    friendlyName = new QLabel(("Luce cucina"));
    vlay->addWidget(deviceName);
    vlay->addWidget(friendlyName);

    hlay->addWidget(ico);
    hlay->addWidget(center);
    hlay->addWidget(button);
}
