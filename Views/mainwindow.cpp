#include "mainwindow.h"
#include "additem.h"


//prova
#include "bulbsettings.h"

MainWindow::MainWindow(MainViewModel* m,QWidget *parent) : model(m), QWidget(parent)
{
    this->model = model;

    setWindowTitle ("DuISmartMainWindow");
    setFixedSize(640,480);

    //Creazione della visualizzazione di default
    defaultTab = new QListWidget(this);
    tab = new QTabWidget(this);
    addDevice = new QPushButton(tr("Aggiungi"), this);

    //tab->addDevicedTab(defaultTab, tr("All"));
    tab->addTab(defaultTab,tr("All"));

    //Main layout finestra
    QVBoxLayout *vLay = new QVBoxLayout(this);
    vLay->addWidget(tab);
    vLay->addWidget(addDevice);

    //Colleggo segnali e slot
    connect(addDevice, SIGNAL(clicked()), this, SLOT(addClieckedHandler()));

    //Imposto lo stile
    setWindowStyle();
    secondaFinestra=new QDialog();



// prova bottone impostazioni (da sostituire)
    QPushButton *b = new QPushButton("impostazioni prova bulb",this);
    vLay->addWidget(b);
    connect(b,SIGNAL(clicked(bool)),this,SIGNAL(AccSettingsBulb()));

// prova bottone imp 2.0
    QPushButton *c = new QPushButton("impostazioni prova display",this);
    vLay->addWidget(c);
    connect(c,SIGNAL(clicked(bool)),this,SIGNAL(AccSettingsDisplay()));
}



void MainWindow::addToAllList() const{

    // ---ATTENZIONE--- esempio di inserimento

    //Creo l'oggetto da inserire nella lista
    QListWidgetItem *item = new QListWidgetItem();
    defaultTab->addItem(item);
    //Creo la custom view dell'oggetto della lista
    BulbListItem *dli = new BulbListItem();
    item->setSizeHint(QSize(0, 100));
    //Associo la custom view all'oggetto della lista
    defaultTab->setItemWidget(item, dli);
}


void MainWindow::addClieckedHandler()
{
    //secondaFinestra ha l'unica funzione di permettere ad exec di bloccare la prima finestra
    AddItem *AddI=new AddItem(secondaFinestra);
    AddI->exec();
    addToAllList();
/*
        PROBLEMA RISCONTRATO: con exec, se dalla finestra figlia si chiude tramite il bottone cancel impedisce
                              la creazione dell'oggetto che viene creato in automatico al click di "Aggiungi" della finestra principale,
                              mentre se la si chiude dalla tab in alto a dx la crea normalmente -->??
*/

}

void MainWindow::setWindowStyle(){
    // Imposto le dimensioni
    setMinimumSize(QSize(400,400));
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    // Imposto il foglio di stile
    QFile file(":/Resources/style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);
}

/*  spostato nel controller
 * // prova settings
void MainWindow::sett(){
    BulbSettings *settings=new BulbSettings();
    settings->show();
}

*/



