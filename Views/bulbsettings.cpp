#include "bulbsettings.h"

BulbSettings::BulbSettings(Settings *parent): Settings(parent)
{
// creazione layout di bulbsettings e inserimento nela prima riga di gLayout
    QVBoxLayout*setBulb=new QVBoxLayout();
    gLayout->addLayout(setBulb,1,1);

//inizializzazione lcdbulb (il 2 indica le cifre del display)
    lcdBulb= new QLCDNumber(3);
    lcdBulb->setSegmentStyle(QLCDNumber::Filled);

    sliderBulb=new QSlider(Qt::Horizontal);
    sliderBulb->setRange(0,100);
    sliderBulb->setValue(0);

    setBulb->addWidget(lcdBulb);
    setBulb->addWidget(sliderBulb);

    connect(sliderBulb,SIGNAL(valueChanged(int)),lcdBulb,SLOT(display(int)));
    //connect(sliderBulb,SIGNAL(valueChanged(int)),controller,SLOT(qualcosa));
    //connect value changed a possibile dispositivo

    //setLayout(gLayout);
}
