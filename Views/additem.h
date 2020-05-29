#ifndef ADDITEM_H
#define ADDITEM_H

//aggiunte per finestra
#include <QFormLayout>
#include <QDialog>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QWidget>
//assicurarsi di rimuovere le classi "prova" a completamento del return
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QComboBox>

//prova
#include <QMenu>
#include <QToolButton>

//aggiunta model Additem
#include "Models/additemmodel.h"



class AddItem : public QDialog
{
    Q_OBJECT
public:
    explicit AddItem(QDialog *parent);

signals:

public slots:
    /**
     * @brief accept: Accettazione campi nuovo elemento
     */
    void accept();

    /**
     * @brief cancel: Chiusura finestra
     */
    void cancel();



private:
    //model per gestione fati finestra
    //additemmodel *model;
    //campi per l'uente
    QLineEdit *name;
    QLineEdit *add;
    QTextEdit *description;
    QComboBox *room;
    QComboBox *device;
    QToolButton *TButton;
    QLineEdit *aggiungiStanza;
};

#endif // ADDITEM_H
