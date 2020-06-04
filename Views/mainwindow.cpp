#include "mainwindow.h"
#include "additemwindow.h"


MainWindow::MainWindow(QWidget *parent) : QWidget(parent){
    setWindowTitle ("DuISmartMainWindow");
    setFixedSize(640,480);

    //Creazione della visualizzazione di default
    tab = new QTabWidget(this);
    addDevice = new QPushButton(tr("Aggiungi"), this);

    //Main layout finestra
    QVBoxLayout *vLay = new QVBoxLayout(this);
    vLay->addWidget(tab);
    vLay->addWidget(addDevice);

    //Colleggo segnali e slot
    connect(addDevice, SIGNAL(clicked()), this, SIGNAL(addNewDevice()));

    //Imposto lo stile
    setWindowStyle();
}

void MainWindow::addTab(const QString& tabName, bool isAll){
    //Viene aggiunto unn nuovo tab con il nome indicato
    isAll ? tab->insertTab(0, new QListWidget(this), tabName) : tab->addTab(new QListWidget(this), tabName);
}

void MainWindow::addToAllTab(DeviceListItem *dli, const QString& tabName) const{
    //cerco la stanza in cui mettere il device
    QListWidget* found = nullptr;
    for (int i = 0; i < tab->count() && !found; ++i) {
        if(tab->tabText(i) == tabName) found = dynamic_cast<QListWidget*>(tab->widget(i));
    }

    //Controllo che found sia un QListWidget/sia stato trovato
    if(found){
        //Creo l'oggetto da inserire nella lista
        QListWidgetItem *item = new QListWidgetItem();
        found->addItem(item);
        //Creo la custom view dell'oggetto della lista
        item->setSizeHint(QSize(0, 100));
        //Associo la custom view all'oggetto della lista
        found->setItemWidget(item, dli);

        //Aggiungo il device nel tab "All" (che e' sempre il tab index 0)
        QListWidget* allTab = dynamic_cast<QListWidget*>(tab->widget(0));
        allTab->addItem(item);
        allTab->setItemWidget(item, dli);
    }
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
