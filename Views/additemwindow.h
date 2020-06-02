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



class AddItemWindow : public QDialog
{
    Q_OBJECT
public:

    /**
     * @brief AddItemWindow: Costruttore di default
     * @param parent
     */
    explicit AddItemWindow(QDialog *parent);

    ~AddItemWindow();

signals:
    /**
     * @brief onDeviceNameChanged: Evento generato quandoil testo del device name viene cambiatoS
     */
    void onDeviceNameChanged(const QString& text);

    /**
     * @brief onFriendlyNameChanged: Evento generato quandoil testo del friendly name viene cambiatoS
     */
    void onFriendlyNameChanged(const QString& text);

    /**
     * @brief onAddNewDevice: Evento generato quando vengono confemrate le impostazioni del nuovo device
     */
    void onAddNewDevice();


private slots:

    /**
     * @brief getChanges: Slot usato per il segnale proveniente dal textChanged di description
     */
    void getChanges();

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
    //campi per l'uente
    QLineEdit *name;
    QTextEdit *description;
    QComboBox *room;
    QComboBox *device;
    QLineEdit *aggiungiStanza;
};

#endif // ADDITEMWINDOW_H
