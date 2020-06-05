#include "bulbsettings.h"

BulbSettings::BulbSettings(Settings *parent): Settings(parent)
{
// creazione layout di bulbsettings e inserimento nela prima riga di gLayout
    QGridLayout *setBulb=new QGridLayout();
    gLayout->addLayout(setBulb,1,1);


//inizializzazione lcdbulb (il 2 indica le cifre del display)
    lcdBulb= new QLCDNumber(3);
    lcdBulb->setSegmentStyle(QLCDNumber::Filled);

    sliderBulb=new QSlider(Qt::Horizontal);
    sliderBulb->setRange(0,100);
    sliderBulb->setValue(0);

    //creazione label uminosità
    setBulb->addWidget(new QLabel("Brightness"),1,1);
//layout per racchiudere lcd e slider
    QVBoxLayout *encase=new QVBoxLayout();
    encase->addWidget(lcdBulb);
    encase->addWidget(sliderBulb);
    //inserimento grid encase in layout setBulb
    setBulb->addLayout(encase,1,2);


//inserimento qcolordialog
    selectColor = new QPushButton("Color");

    setBulb->addWidget(new QLabel("Bulb color"),2,1);
    setBulb->addWidget(selectColor,2,2);
    //setBulb->addWidget(cDialog,2,2);


    connect(sliderBulb,SIGNAL(valueChanged(int)),lcdBulb,SLOT(display(int)));
    //connect(sliderBulb,SIGNAL(valueChanged(int)),controller,SLOT(qualcosa));
    //connect value changed a possibile dispositivo

    //setLayout(gLayout);

    setMinimumSize(300,200);


    //prova colore bottone select color
    connect(selectColor,SIGNAL(clicked(bool)),this,SLOT(pressedSelectColor()));


}

void BulbSettings::pressedSelectColor(){
    emit changeColor(selectColor);
}


void BulbSettings::changeColor(QWidget *button2){


    QColorDialog *cDialog = new QColorDialog(button2);
    QColor colorChoosen = cDialog->getColor();
    button2->setPalette(colorChoosen);
}
