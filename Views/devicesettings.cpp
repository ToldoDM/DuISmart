#include "devicesettings.h"

#include <QPushButton>

DeviceSettings::DeviceSettings(){
    // layout verticale finestra impostazioni
    gLayout = new QGridLayout(this);
}

DeviceSettings::DeviceSettings(const DeviceSettings&){
    gLayout = new QGridLayout(this);
}

DeviceSettings& DeviceSettings::operator=(const DeviceSettings&){
    return *this;
}

void DeviceSettings::closeEvent(QCloseEvent* ev){
    QDialog::closeEvent(ev);
    emit onCloseSettW();
}

DeviceSettings::~DeviceSettings(){
    delete gLayout;
}

