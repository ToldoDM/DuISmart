#include "devicesettings.h"

#include <QPushButton>

Settings::Settings(QWidget *parent): QWidget(parent)
{
// layout verticale finestra impostazioni
    gLayout = new QGridLayout(this);


// dichiarazione bottoni accatta/cancella
    QDialogButtonBox *settingsBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    gLayout->addWidget(settingsBox,2,1);// inserito in questa posizione per permettere alle classi derivate di mettere widget in (1,1)
    connect(settingsBox,SIGNAL(accepted()),this,SLOT(accept()));
    connect(settingsBox,SIGNAL(rejected()),this,SLOT(cancel()));

    this->show();
}

void Settings::accept(){

}

void Settings::cancel(){
    this->close();
}
