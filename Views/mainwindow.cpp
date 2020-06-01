#include "mainwindow.h"
#include "additemwindow.h"


MainWindow::MainWindow(MainViewModel* m,QWidget *parent) : QWidget(parent), model(m){
    setWindowTitle ("DuISmartMainWindow");
    setFixedSize(640,480);

    //Creazione della visualizzazione di default
    defaultTab = new QListWidget(this);
    tab = new QTabWidget(this);
    addDevice = new QPushButton(tr("Aggiungi"), this);

    tab->addTab(defaultTab, tr("All"));

    //Main layout finestra
    QVBoxLayout *vLay = new QVBoxLayout(this);
    vLay->addWidget(tab);
    vLay->addWidget(addDevice);

    //Colleggo segnali e slot
    connect(addDevice, SIGNAL(clicked()), this, SLOT(addClieckedHandler()));

    //Imposto lo stile
    setWindowStyle();
    secondaFinestra=new QDialog();
}

void MainWindow::addToAllTab(DeviceListItem *dli) const{

    //Creo l'oggetto da inserire nella lista
    QListWidgetItem *item = new QListWidgetItem();
    defaultTab->addItem(item);
    //Creo la custom view dell'oggetto della lista
    item->setSizeHint(QSize(0, 100));
    //Associo la custom view all'oggetto della lista
    defaultTab->setItemWidget(item, dli);
}


void MainWindow::addClieckedHandler() const{

    //ATTENZIONE!!! inserimento per testing
    addToAllTab(new BulbListItem(0));
    //secondaFinestra ha l'unica funzione di permettere ad exec di bloccare la prima finestra
    AddItemWindow *AddI= new AddItemWindow(secondaFinestra);
    AddI->exec();
/*
        PROBLEMA RISCONTRATO: con exec, se dalla finestra figlia si chiude tramite il bottone cancel impedisce
                              la creazione dell'oggetto che viene creato in automatico al click di "Aggiungi" della finestra principale,
                              mentre se la si chiude dalla tab in alto a dx la crea normalmente -->??
*/
    //addToAllTab(new BulbListItem(0));
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
