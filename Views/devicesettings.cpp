#include "devicesettings.h"

#include <QPushButton>

Settings::Settings(QWidget *parent): QWidget(parent)
{
// layout verticale finestra impostazioni
    vLayout = new QVBoxLayout(this);

    QPushButton *e=new QPushButton("exit");
    vLayout->addWidget(e);

// dichiarazione bottoni accatta/cancella
    QDialogButtonBox *settingsBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    vLayout->addWidget(settingsBox,Qt::AlignRight,Qt::AlignBottom);
    connect(settingsBox,SIGNAL(accepted()),this,SLOT(accept()));
    connect(settingsBox,SIGNAL(rejected()),this,SLOT(cancel()));
    connect(e,SIGNAL(clicked(bool)),this,SLOT(cancel()));


    this->show();
}

void Settings::accept(){

}

void Settings::cancel(){
    this->destroy();
}
