#include "mainwindow.h"
#include "additemwindow.h"


MainWindow::MainWindow(QWidget *parent) : QWidget(parent){
    setWindowTitle ("DuISmartMainWindow");
    setFixedSize(640,480);

    //Creazione della visualizzazione di default
    tab = new QTabWidget(this);
    addDevice = new QPushButton(tr("Aggiungi un dispositivo"), this);

    //Main layout finestra
    QVBoxLayout *vLay = new QVBoxLayout(this);
    vLay->addWidget(tab);
    vLay->addWidget(addDevice);

    //Colleggo segnali e slot
    connect(addDevice, SIGNAL(clicked()), this, SIGNAL(addNewDevice()));

    //Imposto lo stile
    setWindowStyle();

    //Rendo invisibile QTabWidget perche' non contiene nessun tab
    tab->setVisible(false);
}

void MainWindow::addTab(const QString& tabName){
    //Viene aggiunto unn nuovo tab con il nome indicato
    tab->setCurrentIndex(tab->addTab(new QListWidget(this), tabName));
    tab->setVisible(true);
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
        //Rendo il list item non selezionabile
        item->setFlags(item->flags() & ~Qt::ItemIsSelectable);

        found->addItem(item);
        //Creo la custom view dell'oggetto della lista
        item->setSizeHint(QSize(0, 100));
        //Associo la custom view all'oggetto della lista
        found->setItemWidget(item, dli);
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
