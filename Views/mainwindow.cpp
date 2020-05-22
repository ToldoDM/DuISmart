#include "mainwindow.h"
#include "additem.h"


MainWindow::MainWindow(MainViewModel* m,QWidget *parent) : model(m), QWidget(parent)
{
    this->model = model;

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
}

void MainWindow::addToAllList() const{

    // ---ATTENZIONE--- esempio di inserimento

    //Creo l'oggetto da inserire nella lista
    QListWidgetItem *item = new QListWidgetItem();
    defaultTab->addItem(item);
    //Creo la custom view dell'oggetto della lista
    DeviceListItem *dli = new DeviceListItem();
    item->setSizeHint(QSize(0, 100));
    //Associo la custom view all'oggetto della lista
    defaultTab->setItemWidget(item, dli);
}

void MainWindow::addClieckedHandler()
{
    AddItem *AddI=new AddItem();
    AddI->show();
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
