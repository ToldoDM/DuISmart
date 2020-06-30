#include "additemwindow.h"

AddItemWindow::~AddItemWindow(){

    delete name;
    delete room;
    delete device;
    delete aggiungiStanza;

    delete racchiudiStanza;
    delete buttonBox;
    delete addRoom;
    delete formLayout;
    delete Vlayout;
}

AddItemWindow::AddItemWindow(const AddItemWindow& aiw){

    //dichiarazione dei layout
    Vlayout=new QVBoxLayout(this);
    formLayout=new QFormLayout();

    //ridimensionamenti random
    formLayout->setRowWrapPolicy(QFormLayout::DontWrapRows);
    formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
    formLayout->setFormAlignment(Qt::AlignHCenter | Qt::AlignTop);
    formLayout->setLabelAlignment(Qt::AlignLeft);


    //dichiarazione campi
    name=new QLineEdit(aiw.name->text());


    //Dichiarazione qcombobox stanza e popolamento
    room = new QComboBox(this);
    for (int i=0; i<aiw.room->count(); ++i) {
        room->addItem(aiw.room->itemText(i), aiw.room->itemData(i));
    }
    room->setCurrentIndex(aiw.room->currentIndex());


    //Dichiarazione qcombobox dispositivo e popolamento
    device=new QComboBox(this);
    device->addItem("inserire dispositivo");
    device->addItem(tr("Lampadina"), DeviceType::BULB);
    device->addItem(tr("TV"), DeviceType::TV);
    device->addItem(tr("Termostato"), DeviceType::THERMOSTAT);

    device->setCurrentIndex(aiw.device->currentIndex());

    //inserimento campi in formlayout
    formLayout->addRow("Smart Device Name",name);
    formLayout->addRow("Device",device);
    formLayout->addRow("Room",room);


    /***********************************************************************************/
    //aggiunta feature inserimento nuova stanza
    addRoom=new QPushButton(aiw.addRoom->text());
    racchiudiStanza=new QHBoxLayout();
    aggiungiStanza=new QLineEdit(aiw.aggiungiStanza->text());

    addRoom->setEnabled(aiw.addRoom->isEnabled());
    formLayout->addRow(addRoom,aggiungiStanza);
    /***********************************************************************************/


    //inserimento corretto layout
    Vlayout->removeWidget(buttonBox);
    Vlayout->addLayout(formLayout);
    //da modificare
    Vlayout->addLayout(racchiudiStanza);
    Vlayout->addWidget(buttonBox);

    //Connessioni segnali e slot
    connect(name, SIGNAL(textEdited(const QString&)), this, SLOT(getChanges(const QString&)));
    connect(addRoom,SIGNAL(clicked()),this,SLOT(addNewRoomClicked()));
    connect(aggiungiStanza,SIGNAL(textChanged(const QString&)),this,SLOT(addRoomTextChanged(const QString&)));
}

AddItemWindow& AddItemWindow::operator=(const AddItemWindow &aiw){
    if(this != &aiw){
        delete name;
        delete room;
        delete device;
        delete aggiungiStanza;
        delete addRoom;

        //dichiarazione campi
        name=new QLineEdit(aiw.name->text());


        //Dichiarazione qcombobox stanza e popolamento
        room = new QComboBox(this);
        for (int i=0; i<aiw.room->count(); ++i) {
            room->addItem(aiw.room->itemText(i), aiw.room->itemData(i));
        }
        room->setCurrentIndex(aiw.room->currentIndex());


        //Dichiarazione qcombobox dispositivo e popolamento
        device=new QComboBox(this);
        device->addItem("inserire dispositivo");
        device->addItem(tr("Lampadina"), DeviceType::BULB);
        device->addItem(tr("TV"), DeviceType::TV);
        device->addItem(tr("Termostato"), DeviceType::THERMOSTAT);

        device->setCurrentIndex(aiw.device->currentIndex());

        //inserimento campi in formlayout
        formLayout->addRow("Smart Device Name",name);
        formLayout->addRow("Device",device);
        formLayout->addRow("Room",room);


        /***********************************************************************************/
        //aggiunta feature inserimento nuova stanza
        addRoom=new QPushButton(aiw.addRoom->text());
        aggiungiStanza=new QLineEdit(aiw.aggiungiStanza->text());

        addRoom->setEnabled(aiw.addRoom->isEnabled());
        formLayout->addRow(addRoom,aggiungiStanza);
        /***********************************************************************************/


        //inserimento corretto layout
        Vlayout->removeWidget(buttonBox);
        Vlayout->addLayout(formLayout);
        //da modificare
        Vlayout->addLayout(racchiudiStanza);

        //Connessioni segnali e slot
        connect(name, SIGNAL(textEdited(const QString&)), this, SLOT(getChanges(const QString&)));
        connect(addRoom,SIGNAL(clicked()),this,SLOT(addNewRoomClicked()));
        connect(aggiungiStanza,SIGNAL(textChanged(const QString&)),this,SLOT(addRoomTextChanged(const QString&)));
    }
    return *this;
}

AddItemWindow::AddItemWindow(){

    //dichiarazione dei layout
    Vlayout=new QVBoxLayout(this);
    formLayout=new QFormLayout();

    //ridimensionamenti random
    formLayout->setRowWrapPolicy(QFormLayout::DontWrapRows);
    formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
    formLayout->setFormAlignment(Qt::AlignHCenter | Qt::AlignTop);
    formLayout->setLabelAlignment(Qt::AlignLeft);


    //dichiarazione campi
    name=new QLineEdit("Device name");


    //Dichiarazione qcombobox stanza e popolamento
    room = new QComboBox(this);
    room->addItem(tr("inserire stanza"));


    //Dichiarazione qcombobox dispositivo e popolamento
    device=new QComboBox(this);
    device->addItem("inserire dispositivo");

    device->addItem(tr("Lampadina"), DeviceType::BULB);
    device->addItem(tr("TV"), DeviceType::TV);
    device->addItem(tr("Termostato"), DeviceType::THERMOSTAT);

    device->setCurrentIndex(0);

    //inserimento campi in formlayout
    formLayout->addRow("Smart Device Name",name);
    formLayout->addRow("Device",device);
    formLayout->addRow("Room",room);


    /***********************************************************************************/
    //aggiunta feature inserimento nuova stanza
    addRoom=new QPushButton("Add Room");
    racchiudiStanza=new QHBoxLayout();
    aggiungiStanza=new QLineEdit(this);

    addRoom->setEnabled(false);
    //racchiudiStanza->addWidget(addRoom);
    //racchiudiStanza->addWidget(aggiungiStanza);
    formLayout->addRow(addRoom,aggiungiStanza);
    /***********************************************************************************/


    //inserimento bottoni conferma e cancella + connessioni
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    //inserimento corretto layout
    Vlayout->addLayout(formLayout);
    //da modificare
    Vlayout->addLayout(racchiudiStanza);
    Vlayout->addWidget(buttonBox);

    //Connessioni segnali e slot
    connect(name, SIGNAL(textEdited(const QString&)), this, SLOT(getChanges(const QString&)));
    connect(buttonBox,SIGNAL(accepted()),this,SLOT(accept()));
    connect(buttonBox,SIGNAL(rejected()),this,SLOT(cancel()));
    connect(addRoom,SIGNAL(clicked()),this,SLOT(addNewRoomClicked()));
    connect(aggiungiStanza,SIGNAL(textChanged(const QString&)),this,SLOT(addRoomTextChanged(const QString&)));
}

void AddItemWindow::closeEvent(QCloseEvent *ev){
    QDialog::closeEvent(ev);
    emit closeAddItemW();
}

void AddItemWindow::addRoomTextChanged(const QString& text){
    addRoom->setEnabled(!(text.isNull() || text.isEmpty()));
}

void AddItemWindow::populateRoomsComboBox(QList<const QString *> *list){
    //Aggiungo le stanze alla combo box e segno le stanze gia' presenti con l'enum adeguato
    for (int i=0; i<list->count(); ++i){
        room->addItem(*(*list)[i], RoomType::EXIST);
    }
}

//slot accetta: return dati solo se modificati dall'utente
void AddItemWindow::accept(){

    //se i campi non sono midificati -> "errore"
    if(name->displayText().isEmpty()){ raiseProblemDialog("Inserire un nome al device"); }
    else if(room->currentText()=="inserire stanza" || name->displayText()=="Device name" || device->currentText()=="inserire dispositivo")
    {
        raiseProblemDialog(tr("E' necessario modificare i campi di default"));
    }
    else
    {
        //controllo se la stanza selezionata e' una nuova stanza
        if(room->currentData().canConvert<RoomType>() && room->currentData().value<RoomType>() == RoomType::NEW) emit onAddNewRoom(room->currentText());

        //lancio l'eventi addDevice specificando quale device e' stato scelto
        emit onAddNewDevice(device->currentData().value<DeviceType>(), room->currentText());
    }
}

void AddItemWindow::raiseProblemDialog(const QString &labText){
    QErrorMessage mb;
    mb.showMessage(labText);
    mb.exec();
}

// slot cancel: distruzione widget
void AddItemWindow::cancel(){
    this->close();
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
        room->setCurrentIndex(index<0 ? room->count()-1 : index);
    }
}

void AddItemWindow::getChanges(const QString& text){
    emit onFriendlyNameChanged(text);
}
