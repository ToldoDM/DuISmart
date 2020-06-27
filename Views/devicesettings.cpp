#include "devicesettings.h"

#include <QPushButton>

DeviceSettings::DeviceSettings(){
    // layout verticale finestra impostazioni
    gLayout = new QGridLayout(this);
}

DeviceSettings::~DeviceSettings(){
    delete gLayout;
}

