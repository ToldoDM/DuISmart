#include "additem.h"
#include <QDialogButtonBox>


AddItem::AddItem(QWidget *parent) : QWidget(parent)
{

//Qui verra' gestita la nuova finestra per l'inserimento del nuovo device

//dichiarazione dei layout
    QBoxLayout * layout=new QBoxLayout(QBoxLayout::TopToBottom,this);
    QVBoxLayout *Vlayout=new QVBoxLayout();
    QHBoxLayout *Hlayout=new QHBoxLayout();
    QFormLayout *formLayout=new QFormLayout();

//dichiarazione campi
    name=new QLineEdit("Device name");
    description =new QTextEdit("Device description");


    //Dichiarazione qcombobox e popolamento
    combo=new QComboBox();
    combo->addItem("inserire stanza");
    combo->addItem("Cucina");
    combo->addItem("Salotto");
    combo->addItem("Bagno");
    combo->addItem("Camrea da letto");
    //il primo indice è quello "inserire la stanza"
    //ATTENZIONE A QUESTA PARTE SE SI FA CUSTOM
    combo->setCurrentIndex(0);


    //ridimensionamenti random
    formLayout->setRowWrapPolicy(QFormLayout::DontWrapRows);
    formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
    formLayout->setFormAlignment(Qt::AlignHCenter | Qt::AlignTop);
    formLayout->setLabelAlignment(Qt::AlignLeft);

//aggiunta layout verticale al layout della finestra
    layout->addLayout(Vlayout);

//inserimento campi in formlayout
    formLayout->addRow("Smart Device Name",name);
    formLayout->addRow("Description",description);
    formLayout->addRow("Room",combo);

    //bottoni rifatti più sotto (da vedere quale mantenere, di base sono uguali)
    //QPushButton *reset=new QPushButton("reset");
    //QPushButton *submit=new QPushButton("submit");

    // il layout orizzontale contiene due bottoni e si trova sotto il qformlayout, messi a commento per motivo sopra
    //Hlayout->addWidget(reset);
    //Hlayout->addWidget(submit);

/*
*
*
*   Sarebbe da aggiungere un'ulteriore bottone detto reset, la cui funzione è quella di eliminare le modifiche ai campi
*
*
*/

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(CancField()));

    Hlayout->addWidget(buttonBox);

    Vlayout->addLayout(formLayout);
    Vlayout->addLayout(Hlayout);

    //connessione bottoni-azioni
    //presente bug-arresto
}


void AddItem::accept(){

//se i campi non sono midificati -> "errore"
    if(combo->currentText()=="inserire stanza" || name->displayText()=="Device name" || description->toPlainText()=="Device description")
        {
            QDialog *Problem= new QDialog(this);
            QVBoxLayout *LProblem= new QVBoxLayout(Problem);
            LProblem->addWidget(new QLabel("E' necessario modificare i campi di default",Problem));
            Problem->show();

        }
//se invece i campi sono modificati -> prosegui
    else
    {
        QDialog *dialog= new QDialog(this);
        QVBoxLayout *t= new QVBoxLayout(dialog);

        t->addWidget(new QLabel(name->displayText(),dialog));
        t->addWidget(new QLabel(description->toPlainText(),dialog)); /* <- toPlainText() ottiene e imposta i contenuti
                                                                dell'editor di testo come testo normale */
        t->addWidget(new QLabel(combo->currentText(),dialog));

        dialog->show();

        emit CancField();
    }
}

void AddItem::CancField(){
    name->clear();
    name->setText("Device name");
    description->clear();
    description->insertPlainText("Device description");

    //Con la cancellazione dei campi bisogna riportare combo all'index iniziale
    combo->setCurrentIndex(0);


}
