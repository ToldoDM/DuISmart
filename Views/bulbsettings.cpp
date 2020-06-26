#include "bulbsettings.h"

BulbSettings::BulbSettings(){
    cDialog= new QColorDialog();

    // creazione layout di bulbsettings e inserimento nela prima riga di gLayout
    setBulb=new QGridLayout();
    gLayout->addLayout(setBulb,1,1);

    //inizializzazione lcdbulb (il 2 indica le cifre del display)
    lcdBulb = new QLCDNumber(2,this);
    lcdBulb->setSegmentStyle(QLCDNumber::Filled);

    sliderBulb=new QSlider(Qt::Horizontal);
    sliderBulb->setRange(0,100);
    sliderBulb->setValue(0);

    //creazione label uminosità
    setBulb->addWidget(new QLabel("Brightness"),1,1);
    //layout per racchiudere lcd e slider
    encase=new QVBoxLayout();
    encase->addWidget(lcdBulb);
    encase->addWidget(sliderBulb);
    //inserimento grid encase in layout setBulb
    setBulb->addLayout(encase,1,2);


    //inserimento qcolordialog
    selectColor = new QPushButton("Color");

    setBulb->addWidget(new QLabel("Bulb color"),2,1);
    setBulb->addWidget(selectColor,2,2);
    //setBulb->addWidget(cDialog,2,2);


    //connessione qslider -> display
    connect(sliderBulb,SIGNAL(valueChanged(int)),lcdBulb,SLOT(display(int)));

    //setLayout(gLayout);
    setMinimumSize(300,200);

    //alla pressione del bottone selectColor si apre la finestra della scelta del colore
    connect(selectColor,SIGNAL(clicked(bool)),this,SLOT(pressedSelectColor()));

    //connessione segnale conferma di cDialog -> cambio colore del bottone selectColor
    connect(cDialog,SIGNAL(colorSelected(QColor)),this,SLOT(bulbSelectedColor()));


//connessione segnale conferma di cDialog -> cambio colore del bottone selectColor
   // connect(BulbS->cDialog,SIGNAL(colorSelected(QColor)),this,SLOT(ChangeToSelectedColor(QColor)));
}

BulbSettings::~BulbSettings(){
    delete selectColor;
    delete lcdBulb;
    delete cDialog;
    delete sliderBulb;
    delete bulbColor;
    delete setBulb;
    delete encase;
}

void BulbSettings::pressedSelectColor() const{
        cDialog->show();
}

void BulbSettings::bulbSelectedColor(){
    selectColor->setPalette(cDialog->selectedColor());
}

void BulbSettings::accept(){
    emit bulbExtractedData(cDialog->selectedColor(), sliderBulb->value());
}

