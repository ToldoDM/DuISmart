#include "thermostatsettings.h"

ThermostatSettings::ThermostatSettings(Settings *parent): Settings(parent)
{
    QHBoxLayout *hlay=new QHBoxLayout();
    gLayout->addLayout(hlay,1,1);

    // xreazione bottoni aumento e decremento + layout
    QVBoxLayout *vlay = new QVBoxLayout();
    increase = new QPushButton();
    QIcon up(":/Images/Up.png");
    increase->setIcon(up);
    increase->setMinimumSize(50,50);
    increase->setIconSize(QSize(50,50));
    //increase->setStyleSheet("*{border-image: url (:/Images/bulb.png)}");

    decrease = new QPushButton();
    QIcon down(":/Images/Down.png");
    increase->setIcon(down);
    increase->setMinimumSize(50,50);

    //inserimento bottoni in layout
    vlay->addWidget(increase);
    vlay->addWidget(decrease);

    //inserimento layout verticale in quello orizzontale
    hlay->addLayout(vlay);

    //creazione display ed inserimento nel layout orizzontale
    num = new QLCDNumber(2,this);
    hlay->addWidget(num);

    connect(increase,SIGNAL(clicked()),this,SLOT(displayIncreased()));
    connect(decrease,SIGNAL(clicked()),this,SLOT(displayDecreased()));
}


void ThermostatSettings::displayIncreased(){
    int i= num->value();
    emit num->display(i+1);
}

void ThermostatSettings::displayDecreased(){
    int i= num->value();
    emit num->display(i-1);
}

void ThermostatSettings::accept(){
    emit ThermostatExtractedData(num->value());
    emit Settings::cancel();
}
