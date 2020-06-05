#include "additemwindow.h"

AddItemWindow::~AddItemWindow(){
    delete name;
    delete description;
    delete room;
    delete device;
    delete aggiungiStanza;

    delete labelText;
    delete LProblem;
}

AddItemWindow::AddItemWindow(QDialog *parent) : QDialog(parent){
    //Qui verra' gestita la nuova finestra per l'inserimento del nuovo device
    Problem = new QDialog(this);
    LProblem = new QVBoxLayout(Problem);
    labelText = new QLabel(Problem);
    LProblem->addWidget(labelText);

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
    room = new QComboBox(this);
    room->addItem(tr("inserire stanza"));

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
    connect(addRoom,SIGNAL(clicked()),this,SLOT(addNewRoomClicked()));

}

void AddItemWindow::populateRoomsComboBox(QList<const QString *> *list){
    //Aggiungo le stanze alla combo box e segno le stanze gia' presenti con l'enum adeguato
    for (int i=0; i<list->count(); ++i) room->addItem(*(*list)[i], RoomType::EXIST);
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
        //controllo se la stanza selezionata e' una nuova stanza
        if(room->currentData().userType() == RoomType::NEW) emit onAddNewRoom(room->currentText());

        //In base al tipo di device scelto, creo l'oggetto corrispondente
        emit onAddNewDevice(device->currentData().userType(), room->currentText());
    }
}

void AddItemWindow::raiseProblemDialog(const QString &labText){
    labelText->setText(labText);
    Problem->show();
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
        //Aggiungo la stanza alla combo box e segno le stanze gia' nuove con l'enum adeguato
        int index = room->findText(roomName);
        if(index<0) room->addItem(roomName, RoomType::NEW);
        aggiungiStanza->setText("");
    }
}

void AddItemWindow::getChanges(){
    emit onFriendlyNameChanged(description->toPlainText());
}
