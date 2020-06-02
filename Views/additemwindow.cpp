#include "additemwindow.h"

AddItemWindow::~AddItemWindow(){
    delete name;
    delete description;
    delete room;
    delete device;
    delete aggiungiStanza;
}

AddItemWindow::AddItemWindow(QDialog *parent) : QDialog(parent){
    //Qui verra' gestita la nuova finestra per l'inserimento del nuovo device

    //dichiarazione dei layout
    QVBoxLayout *Vlayout=new QVBoxLayout(this);
    QFormLayout *formLayout=new QFormLayout();

    //ridimensionamenti random
    formLayout->setRowWrapPolicy(QFormLayout::DontWrapRows);
    formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
    formLayout->setFormAlignment(Qt::AlignHCenter | Qt::AlignTop);
    formLayout->setLabelAlignment(Qt::AlignLeft);


    //dichiarazione campi
    name=new QLineEdit("Device name");
    description =new QTextEdit("Device description");


    //Dichiarazione qcombobox stanza e popolamento
    room=new QComboBox(this);

    /*for(int i=0;model->camere->count()>i;i++)
    {
        room->addItem(model->camere->operator [](i));
    }
    //il primo indice è quello "inserire la stanza"
    //ATTENZIONE A QUESTA PARTE SE SI FA CUSTOM
    room->setCurrentIndex(0);*/


    //Dichiarazione qcombobox dispositivo e popolamento
    device=new QComboBox(this);
    device->addItem("inserire dispositivo");

    device->addItem(tr("Lampadina"), DeviceType::BULB);

    device->setCurrentIndex(0);



    //aggiunta layout verticale al layout della finestra
    //layout->addLayout(Vlayout);

    //inserimento campi in formlayout
    formLayout->addRow("Smart Device Name",name);
    formLayout->addRow("Description",description);
    formLayout->addRow("Room",room);
    formLayout->addRow("Device",device);


    /***********************************************************************************/
    //DA RIFARE TUTTO IL LAYOUT (METTERE GRIGLIA O ALTRO)
    //aggiunta feature inserimento nuova stanza
    QPushButton *addRoom=new QPushButton("Add Room");
    QHBoxLayout *racchiudiStanza=new QHBoxLayout();

    aggiungiStanza=new QLineEdit("Inserire nuova stanza",this);
    racchiudiStanza->addWidget(aggiungiStanza);
    racchiudiStanza->addWidget(addRoom);


    /***********************************************************************************/


    //inserimento bottoni conferma e cancella + connessioni
    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    //inserimento corretto layout
    Vlayout->addLayout(formLayout);
    //da modificare
    Vlayout->addLayout(racchiudiStanza);
    Vlayout->addWidget(buttonBox);

    //Connessioni segnali e slot
    connect(name, SIGNAL(textEdited(const QString&)), this, SIGNAL(onDeviceNameChanged(const QString&)));
    connect(description, SIGNAL(textChanged()), this, SLOT(getChanges()));
    connect(buttonBox,SIGNAL(accepted()),this,SLOT(accept()));
    connect(buttonBox,SIGNAL(rejected()),this,SLOT(cancel()));
    connect(addRoom,SIGNAL(clicked(bool)),this,SLOT(sendData()));

}

//slot accetta: return dati solo se modificati dall'utente
void AddItemWindow::accept(){

    //se i campi non sono midificati -> "errore"
    if(room->currentText()=="inserire stanza" || name->displayText()=="Device name" || description->toPlainText()=="Device description" || room->currentText()=="inserire dispositivo")
    {
        QDialog *Problem= new QDialog(this);
        QVBoxLayout *LProblem= new QVBoxLayout(Problem);
        LProblem->addWidget(new QLabel("E' necessario modificare i campi di default",Problem));
        Problem->show();
    }

    //se invece i campi sono modificati -> prosegui7
    //da modificare e mettere creazione oggetto da aggiungere alla lista
    else
    {
        switch (device->currentData().userType()) {
        case DeviceType::BULB:
            break;
        default:
            break;
        }

        emit onAddNewDevice();
    }
}


// slot cancel: distruzione widget
void AddItemWindow::cancel(){
    this->destroy();
}

//aggiunta stringa alle camere e aggiornamento lista room
void AddItemWindow::sendData(){
    //if(aggiungiStanza->displayText() != "Inserire nuova stanza") <- manca inserire controllo
    /*emit model->insert(aggiungiStanza->displayText());
    room->addItem(model->camere->operator [](model->camere->count()-1));*/
}

void AddItemWindow::getChanges(){
    emit onFriendlyNameChanged(description->toPlainText());
}
