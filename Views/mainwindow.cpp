#include "mainwindow.h"



MainWindow::MainWindow(MainViewModel* model, QWidget *parent) : QWidget(parent)
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

void MainWindow::addClieckedHandler(){

    //Qui verra' gestita la nuova finestra per l'inserimento del nuovo device

    //dichiarazione dei layout
    QDialog *wind=new QDialog(this);
    QVBoxLayout *Vlayout=new QVBoxLayout(wind);
    QHBoxLayout *Hlayout=new QHBoxLayout();
    QFormLayout *formLayout=new QFormLayout();
    combo=new QComboBox(this);


    //dichiarazione campi
    name=new QLineEdit("Device name");
    description =new QTextEdit("Device description");

    //ridimensionamenti random
    formLayout->setRowWrapPolicy(QFormLayout::DontWrapRows);
    formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
    formLayout->setFormAlignment(Qt::AlignHCenter | Qt::AlignTop);
    formLayout->setLabelAlignment(Qt::AlignLeft);

    //inserimento campi in formlayout
    formLayout->addRow("Nome Smart Device",name);
    formLayout->addRow("Description",description);
    formLayout->addRow("Stanza",combo);

    //popolamento stanza:
    combo->addItem("Inserire stanza");
    combo->addItem("Cucina");
    combo->addItem("Salotto");
    combo->addItem("Bagno");
    combo->addItem("Camera da letto");


    QPushButton *reset=new QPushButton("reset");
    QPushButton *submit=new QPushButton("submit");


    // il layout orizzontale contiene due bottoni e si trova sotto il qformlayout
    Hlayout->addWidget(reset);
    Hlayout->addWidget(submit);

    Vlayout->addLayout(formLayout);


    Vlayout->addLayout(Hlayout);


    //connessione bottoni-azioni
    connect(reset, SIGNAL(clicked()),this, SLOT(CancField()));
    connect(submit, SIGNAL(clicked()),this, SLOT(Accept()));

    wind->show();
}

void MainWindow::Accept(){

    if(combo->currentText()=="Inserire stanza")
    {
        QDialog *dialog= new QDialog(this);
        QVBoxLayout *t= new QVBoxLayout(dialog);

        t->addWidget(new QLabel("E' necessario inserire una stanza",dialog));
        dialog->show();
    }

    else
    {
        QDialog *dialog= new QDialog(this);
        QVBoxLayout *t= new QVBoxLayout(dialog);

        t->addWidget(new QLabel(name->displayText(),dialog));
        t->addWidget(new QLabel(description->toPlainText(),dialog)); /* <- toPlainText() ottiene e imposta i contenuti
                                                                    dell'editor di testo come testo normale */
        t->addWidget(new QLabel(combo->currentText()));

        dialog->show();
        emit CancField();
    }
}

void MainWindow::CancField(){
    name->clear();
    name->insert("Device Name");
    description->clear();
    description->insertPlainText("Device description");
}



void MainWindow::setWindowStyle() {
    // Imposto le dimensioni
    setMinimumSize(QSize(400,400));
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    // Imposto il foglio di stile
    QFile file(":/Resources/style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);
}
