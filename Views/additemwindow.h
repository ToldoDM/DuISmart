#ifndef ADDITEMWINDOW_H
#define ADDITEMWINDOW_H

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
#include <QDialogButtonBox>

//prova
#include <QMenu>
#include <QToolButton>
#include "Enums/devicetype.h"

//aggiunta model Additem
#include "Models/additemmodel.h"



class AddItemWindow : public QDialog
{
    Q_OBJECT
public:
    explicit AddItemWindow(QDialog *parent);

signals:
    /**
     * @brief onNewDevice: Evento lanciato quando viene richiesto l'inserimento di un nuovo device
     * @param device: Nuovo device da aggiungere
     */
    void onNewDevice(SmartDevice* device);


private slots:
    /**
     * @brief accept: Accettazione campi nuovo elemento
     */
    void accept();

    /**
     * @brief cancel: Chiusura finestra
     */
    void cancel();

    /**
     * @brief sendData: segnale che permette invio di qstring per creazione di una nuova stanza
     */
    void sendData();

private:
    //model per gestione fati finestra
    AddItemModel *model;
    //campi per l'uente
    QLineEdit *name;
    QLineEdit *add;
    QTextEdit *description;
    QComboBox *room;
    QComboBox *device;
    QToolButton *TButton;
    QLineEdit *aggiungiStanza;
};

#endif // ADDITEMWINDOW_H
