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

    connect(increase,SIGNAL(clicked()),this,SLOT(increse()));
    connect(decrease,SIGNAL(clicked()),this,SLOT(decrese()));

    setFixedSize(400,250);

}

void ThermostatSettings::setCurrentSettings(const SettingData &data){
    num->display(data.temp);
}


ThermostatSettings::~ThermostatSettings(){
    delete increase;
    delete decrease;
    delete num ;
    delete vlay;
    delete hlay;
}

void ThermostatSettings::decrese(){
    int i = static_cast<int>(num->value());
    if(i>13){
        num->display(i-1);
        setSettings();
    }
}

void ThermostatSettings::increse(){
    int i = static_cast<int>(num->value());
    if(i<30) {
        num->display(i+1);
        setSettings();
    }
}

void ThermostatSettings::setSettings() const{
    SettingData data(idDevice);
    data.temp = static_cast<int>(num->value());
    emit onSetNewSettings(data);
}
