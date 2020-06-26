#include "thermostatsettings.h"

ThermostatSettings::ThermostatSettings(int ID){
    idDevice = ID;

    hlay=new QHBoxLayout();
    gLayout->addLayout(hlay,1,1);

    // xreazione bottoni aumento e decremento + layout
    vlay = new QVBoxLayout();
    increase = new QPushButton();
    QIcon up(":/Images/Up.png");
    increase->setIcon(up);
    increase->setMinimumSize(50,50);

    decrease = new QPushButton();
    QIcon down(":/Images/Down.png");
    decrease->setIcon(down);
    decrease->setMinimumSize(50,50);

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

    this->setMaximumSize(400,250);

}

ThermostatSettings::~ThermostatSettings(){
    delete increase;
    delete decrease;
    delete num ;
    delete hlay;
    delete vlay;
}


void ThermostatSettings::displayIncreased(){
    int i= num->value();
    if(i<45)
        num->display(i+1);
}

void ThermostatSettings::displayDecreased(){
    int i= num->value();
    if(i>0)
        num->display(i-1);
}

void ThermostatSettings::accept(){
    emit ThermostatExtractedData(idDevice,num->value());
    emit DeviceSettings::cancel();
}
