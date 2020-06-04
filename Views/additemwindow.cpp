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
    device->addItem(tr("TV"), DeviceType::TV);
    device->addItem(tr("Termostato"), DeviceType::THERMOSTAT);

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

    aggiungiStanza=new QLineEdit(this);
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
    connect(addRoom,SIGNAL(clicked()),this,SLOT(addNewRoom()));

}

//slot accetta: return dati solo se modificati dall'utente
void AddItemWindow::accept(){

    //se i campi non sono midificati -> "errore"
    if(room->currentText()=="inserire stanza" || name->displayText()=="Device name" || description->toPlainText()=="Device description" || device->currentText()=="inserire dispositivo")
    {
        raiseProblemDialog(tr("E' necessario modificare i campi di default"));
    }
    else
    {
        switch (device->currentData().userType()) {
        case DeviceType::BULB:
            break;
        case DeviceType::TV:
            break;
        case DeviceType::THERMOSTAT:
            break;
        default:
            break;
        }

        emit onAddNewDevice();
    }
}

void AddItemWindow::raiseProblemDialog(const QString &labText){
    QDialog Problem(this);
    QVBoxLayout LProblem(&Problem);
    QLabel labelText(labText, &Problem);
    LProblem.addWidget(&labelText);
    Problem.show();
}

// slot cancel: distruzione widget
void AddItemWindow::cancel(){
    this->destroy();
}

//aggiunta stringa alle camere e aggiornamento lista room
void AddItemWindow::addNewRoomClicked(){
    QString roomName = aggiungiStanza->displayText();
    if(roomName.isNull() || roomName.isEmpty()) {
        raiseProblemDialog(tr("E' necessario modificare il nome della stanza"));
    }
    else{
        emit onAddNewRoom(roomName);
    }
}

void AddItemWindow::getChanges(){
    emit onFriendlyNameChanged(description->toPlainText());
}
