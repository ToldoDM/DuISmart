#include "devicelistitem.h"

DeviceListItem::DeviceListItem(QWidget *parent) : QWidget(parent) {

    hlay = new QHBoxLayout(this);
    label = new QLabel(("testo prova"));
    button = new QPushButton(("bottone"));
    hlay->addWidget(label);
    hlay->addWidget(button);
}
