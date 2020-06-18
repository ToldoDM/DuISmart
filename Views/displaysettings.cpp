#include "displaysettings.h"
#include <QLabel>


DisplaySettings::DisplaySettings(Settings *parent): Settings(parent)
{

// creazione layout di bulbsettings e inserimento nela prima riga di gLayout
    QGridLayout *setDisplay=new QGridLayout();
    QVBoxLayout *vlay=new QVBoxLayout();
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


    // da fare i tasti telecomando


/*
// refresh rate
    QHBoxLayout *hlay=new QHBoxLayout();
    refreshRate = new QComboBox();
    QLabel *refresh = new QLabel("Select refresh rate");

    hlay->addWidget(refresh);
    hlay->addWidget(refreshRate);

    vlay->addLayout(hlay);

*/ //non so se metterlo

    //creazione bottone e spinbox(range numeri)
    QHBoxLayout *chHLay=new QHBoxLayout();
    spinBox=new QSpinBox();
    QPushButton *Channel=new QPushButton("Change channel");
    //gestione layout
    chHLay->addWidget(Channel);
    chHLay->addWidget(spinBox);

    vlay->addLayout(chHLay);

    spinBox->setRange(1,100);



// dimensioni minime
    this->setMinimumSize(450,250);


    //connessione segnale value changed con segnale ChangeContrast che verrà intercettato dal controller
    connect(sliderCont,SIGNAL(valueChanged(int)),lcdCont,SLOT(display(int)));

    //connessione segnale value changed con segnale ChangeBrightness che verrà intercettato dal controller
    connect(sliderBright,SIGNAL(valueChanged(int)),lcdBright,SLOT(display(int)));

    //connessione bottone change channel con invio del nuovo canale
    connect(Channel,SIGNAL(clicked(bool)),this,SLOT(newChannel()));
}


void DisplaySettings::accept(){
    emit displayExtractedData(lcdCont->value(),lcdBright->value());
    emit setNewChannel(spinBox->value());
    emit Settings::cancel();
}

void DisplaySettings::newChannel(){
    emit setNewChannel(spinBox->value());
}

