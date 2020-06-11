#include "thermostatsettings.h"

thermostatSettings::thermostatSettings(Settings *parent): Settings(parent)
{
    QHBoxLayout *hlay=new QHBoxLayout();
    gLayout->addLayout(hlay,1,1);

    // xreazione bottoni aumento e decremento + layout
    QVBoxLayout *vlay = new QVBoxLayout();
    increase = new QPushButton();
/*
 * prova
*/
    decrease = new QPushButton();

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


void thermostatSettings::displayIncreased(){
    int i= num->value();
    emit num->display(i+1);
}

void thermostatSettings::displayDecreased(){
    int i= num->value();
    emit num->display(i-1);
}
