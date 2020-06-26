#include "devicesettings.h"

#include <QPushButton>

DeviceSettings::DeviceSettings(){
    // layout verticale finestra impostazioni
    gLayout = new QGridLayout(this);

    // dichiarazione bottoni accatta/cancella
    settingsBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    gLayout->addWidget(settingsBox,2,1);// inserito in questa posizione per permettere alle classi derivate di mettere widget in (1,1)
    connect(settingsBox,SIGNAL(accepted()),this,SLOT(accept()));
    connect(settingsBox,SIGNAL(rejected()),this,SLOT(cancel()));
}

DeviceSettings::~DeviceSettings(){
    delete settingsBox;
    delete gLayout;
}

void DeviceSettings::accept(){}

void DeviceSettings::cancel(){ this->close(); }
