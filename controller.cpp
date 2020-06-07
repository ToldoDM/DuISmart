#include "controller.h"

Controller::Controller(QObject* parent) : QObject(parent){
    MainVM = new MainViewModel();
    MainW = new MainWindow(MainVM);

    //connessioni segnali e slot
    connect(MainW,SIGNAL(AccSettings()),this,SLOT(riseBulbSettingsWindow()));
}

void Controller::ShowMainWindow() const { MainW->show(); }

//in questa classe gestisco tutte le viste e i model


void Controller::riseBulbSettingsWindow(){
    BulbS=new BulbSettings();
    BulbS->show();

    //connessioni con impostazioni bulb
    connect(BulbS,SIGNAL(pressedSelectColor()),this, SLOT(BulbSelectColor()));

    //connessione slider-display
    connect(BulbS,SIGNAL(ChangeDisplayInt(int)),BulbS->lcdBulb,SLOT(display(int)));
    //non so se lcdBulb debba essere messa come private e gestire questo segnale direttamente da bulbsettings

    //connessione segnale conferma di cDialog -> cambio colore del bottone selectColor
    connect(BulbS,SIGNAL(selectedColor( const QColor)),this,SLOT(ChangeToSelectedColor(const QColor)));
    //ho messo cambio di colore al bottone a caso, in realtà dovrebbe essere inviato al dispositivo fisico

    connect(BulbS, SIGNAL(extractedData(const QColor,const int)),this,SLOT(getBulbSettings(const QColor, const int)));
}


//mostra finestra
void Controller::BulbSelectColor() const{
    BulbS->cDialog->show();
}

//modifica sfondo bottone
void Controller::ChangeToSelectedColor( const QColor colorSelected) const{
    BulbS->selectColor->setPalette(colorSelected);
}

//fare qualcosa con modifiche
void Controller::getBulbSettings(const QColor color, const int displayValue){
    // inviare modifiche a dispositivo

}
