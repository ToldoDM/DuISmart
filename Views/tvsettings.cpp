#include "tvsettings.h"
#include <QLabel>


TvSettings::TvSettings(int ID){
    idDevice = ID;

    // creazione layout di bulbsettings e inserimento nela prima riga di gLayout
    setDisplay=new QGridLayout();
    vlay=new QVBoxLayout();
    gLayout->addLayout(vlay,1,1);
    vlay->addLayout(setDisplay);



    // contrasto
    lcdCont= new QLCDNumber(3);
    lcdCont->setSegmentStyle(QLCDNumber::Filled);

    sliderCont=new QSlider(Qt::Vertical);
    sliderCont->setRange(0,100);
    sliderCont->setValue(0);

    setDisplay->addWidget(new QLabel("Contrast"),1,1);
    setDisplay->addWidget(lcdCont,2,1);
    setDisplay->addWidget(sliderCont,2,2);

    // luminosita
    lcdBright= new QLCDNumber(3);
    lcdBright->setSegmentStyle(QLCDNumber::Filled);

    sliderBright=new QSlider(Qt::Vertical);
    sliderBright->setRange(0,100);
    sliderBright->setValue(0);

    setDisplay->addWidget(new QLabel("Brightness"),1,3);
    setDisplay->addWidget(lcdBright,2,3);
    setDisplay->addWidget(sliderBright,2,4);


    //creazione bottone e spinbox(range numeri)
    chHLay=new QHBoxLayout();
    spinBox=new QSpinBox();
    Channel=new QPushButton("Change channel");
    //gestione layout
    chHLay->addWidget(Channel);
    chHLay->addWidget(spinBox);

    vlay->addLayout(chHLay);

    spinBox->setRange(1,100);

    // dimensioni minime
    setFixedSize(450,250);

    //connessione segnale value changed con segnale ChangeContrast
    connect(sliderCont,SIGNAL(valueChanged(int)),lcdCont,SLOT(display(int)));
    connect(sliderCont,SIGNAL(valueChanged(int)),this,SLOT(setSettings()));

    //connessione segnale value changed con segnale ChangeBrightness
    connect(sliderBright,SIGNAL(valueChanged(int)),lcdBright,SLOT(display(int)));
    connect(sliderBright,SIGNAL(valueChanged(int)),this,SLOT(setSettings()));

    //connessione bottone change channel con invio del nuovo canale
    connect(Channel,SIGNAL(clicked(bool)),this,SLOT(setSettings()));
}

void TvSettings::setCurrentSettings(const SettingData &data){
    sliderCont->setValue(data.contrast);
    sliderBright->setValue(data.brightness);
    spinBox->setValue(data.channel);
}

TvSettings::~TvSettings(){
    delete Channel;
    delete chHLay;
    delete lcdCont;
    delete sliderCont;
    delete lcdBright;
    delete sliderBright;
    delete spinBox;
    delete setDisplay;
    delete vlay;
}

void TvSettings::setSettings() const{
    SettingData data(idDevice);
    data.channel = spinBox->value();
    data.contrast = static_cast<int>(lcdCont->value());
    data.brightness = static_cast<int>(lcdBright->value());
    emit onSetNewSettings(data);
}

