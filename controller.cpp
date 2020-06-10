#include "controller.h"

Controller::Controller(QObject* parent) : QObject(parent){
    MainVM = new MainViewModel();
    MainW = new MainWindow(MainVM);

    //connessioni segnali e slot
    connect(MainW,SIGNAL(AccSettingsBulb()),this,SLOT(riseBulbSettingsWindow()));

    connect(MainW,SIGNAL(AccSettingsDisplay()),this, SLOT(riseDisplaySettings()));
}

void Controller::ShowMainWindow() const { MainW->show(); }

//in questa classe gestisco tutte le viste e i model


void Controller::riseBulbSettingsWindow(){

    /*BulbS=new BulbSettings();
    BulbS->show();


    //connessione per intercettare dati estratti
    connect(BulbS, SIGNAL(extractedData(const QColor,const int)),this,SLOT(getBulbSettings(const QColor, const int)));
*/
    TherS=new thermostatSettings();
    TherS->show();
}

void Controller::getBulbSettings(const QColor colore, const int valore){
    //fare qualcosa con i valori restituiti
}

void Controller::riseDisplaySettings(){

    DispS= new DisplaySettings();
    DispS->show();
}

void Controller::getDisplaySettings(const int contrast, const int brightness){
    //fare qualcosa
}
