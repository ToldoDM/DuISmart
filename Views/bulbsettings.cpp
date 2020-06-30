#include "bulbsettings.h"

BulbSettings::BulbSettings(int devId){

    idDevice = devId;

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

    //connessione qslider -> display
    connect(sliderBulb,SIGNAL(valueChanged(int)),lcdBulb,SLOT(display(int)));
    connect(sliderBulb,SIGNAL(valueChanged(int)),this,SLOT(setSettings()));

    //setLayout(gLayout);
    setFixedSize(300,200);

    //alla pressione del bottone selectColor si apre la finestra della scelta del colore
    connect(selectColor,SIGNAL(clicked(bool)),this,SLOT(pressedSelectColor()));

    //connessione segnale conferma di cDialog -> cambio colore del bottone selectColor
    connect(cDialog,SIGNAL(colorSelected(QColor)),this,SLOT(bulbSelectedColor()));

}

BulbSettings::BulbSettings(const BulbSettings& bs) : DeviceSettings(bs){
    idDevice = bs.idDevice;

    cDialog= new QColorDialog();

    // creazione layout di bulbsettings e inserimento nela prima riga di gLayout
    setBulb=new QGridLayout();
    gLayout->addLayout(setBulb,1,1);

    //inizializzazione lcdbulb (il 2 indica le cifre del display)
    lcdBulb = new QLCDNumber(2,this);
    lcdBulb->setSegmentStyle(QLCDNumber::Filled);

    sliderBulb=new QSlider(Qt::Horizontal);
    sliderBulb->setRange(0,100);
    sliderBulb->setValue(bs.sliderBulb->value());

    //creazione label uminosità
    setBulb->addWidget(new QLabel("Brightness"),1,1);
    //layout per racchiudere lcd e slider
    encase=new QVBoxLayout();
    encase->addWidget(lcdBulb);
    encase->addWidget(sliderBulb);
    //inserimento grid encase in layout setBulb
    setBulb->addLayout(encase,1,2);


    //inserimento qcolordialog
    selectColor = new QPushButton(bs.selectColor->text());
    selectColor->setPalette(selectColor->palette());

    setBulb->addWidget(new QLabel("Bulb color"),2,1);
    setBulb->addWidget(selectColor,2,2);

    //connessione qslider -> display
    connect(sliderBulb,SIGNAL(valueChanged(int)),lcdBulb,SLOT(display(int)));
    connect(sliderBulb,SIGNAL(valueChanged(int)),this,SLOT(setSettings()));

    //setLayout(gLayout);
    setFixedSize(300,200);

    //alla pressione del bottone selectColor si apre la finestra della scelta del colore
    connect(selectColor,SIGNAL(clicked(bool)),this,SLOT(pressedSelectColor()));

    //connessione segnale conferma di cDialog -> cambio colore del bottone selectColor
    connect(cDialog,SIGNAL(colorSelected(QColor)),this,SLOT(bulbSelectedColor()));
}

BulbSettings& BulbSettings::operator=(const BulbSettings& bs){
    DeviceSettings::operator=(bs);
    if(this != &bs){
        delete selectColor;
        delete lcdBulb;
        delete cDialog;
        delete sliderBulb;

        idDevice = bs.idDevice;

        cDialog= new QColorDialog();

        //inizializzazione lcdbulb (il 2 indica le cifre del display)
        lcdBulb = new QLCDNumber(2,this);
        lcdBulb->setSegmentStyle(QLCDNumber::Filled);

        sliderBulb=new QSlider(Qt::Horizontal);
        sliderBulb->setRange(0,100);
        sliderBulb->setValue(bs.sliderBulb->value());

        //layout per racchiudere lcd e slider
        encase->addWidget(lcdBulb);
        encase->addWidget(sliderBulb);
        //inserimento grid encase in layout setBulb
        setBulb->addLayout(encase,1,2);


        //inserimento qcolordialog
        selectColor = new QPushButton(bs.selectColor->text());
        selectColor->setPalette(selectColor->palette());
        setBulb->addWidget(selectColor,2,2);

        //connessione qslider -> display
        connect(sliderBulb,SIGNAL(valueChanged(int)),lcdBulb,SLOT(display(int)));
        connect(sliderBulb,SIGNAL(valueChanged(int)),this,SLOT(setSettings()));

        //setLayout(gLayout);
        setFixedSize(300,200);

        //alla pressione del bottone selectColor si apre la finestra della scelta del colore
        connect(selectColor,SIGNAL(clicked(bool)),this,SLOT(pressedSelectColor()));

        //connessione segnale conferma di cDialog -> cambio colore del bottone selectColor
        connect(cDialog,SIGNAL(colorSelected(QColor)),this,SLOT(bulbSelectedColor()));
    }
    return *this;
}

void BulbSettings::setCurrentSettings(const SettingData &data){
    selectColor->setPalette(QColor(data.red, data.green, data.blue));
    sliderBulb->setValue(data.brightness);
}

BulbSettings::~BulbSettings(){
    delete encase;
    delete selectColor;
    delete lcdBulb;
    delete cDialog;
    delete sliderBulb;
    delete setBulb;
}

void BulbSettings::pressedSelectColor() const{ cDialog->show(); }

void BulbSettings::bulbSelectedColor(){
    selectColor->setPalette(cDialog->selectedColor());
    setSettings();
}

void BulbSettings::setSettings() const{
    SettingData data(idDevice);
    data.brightness = sliderBulb->value();
    data.red = cDialog->selectedColor().red();
    data.green = cDialog->selectedColor().green();
    data.blue = cDialog->selectedColor().blue();

    emit onSetNewSettings(data);
}

