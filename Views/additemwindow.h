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

#include <QGridLayout>

//prova
#include <QMenu>
#include <QToolButton>
#include "Enums/devicetype.h"
#include "Enums/RoomType.h"



class AddItemWindow : public QDialog
{
    Q_OBJECT
public:

    /**
     * @brief AddItemWindow: Costruttore di default
     * @param parent
     */
    explicit AddItemWindow();

    ~AddItemWindow();

    /**
     * @brief populateRoomsComboBox: Aggiunge alla combo box le camere attualmente presenti
     * @param list: lista camere
     */
    void populateRoomsComboBox(QList<const QString*>* list);

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
     * @param dType: Device type scelto
     * @param roomName: nome stanza
     */
    void onAddNewDevice(DeviceType dType, const QString& roomNameS);

    /**
     * @brief addNewRoom: Evento generato alla pressione del pulsante aggiungi stanza
     * @param roomName: nome stanza
     */
    void onAddNewRoom(const QString& roomName);


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
     * @brief addNewRoomClicked: Slot utilizzato per la gestione dell'aggiunta della nuova stanza
     */
    void addNewRoomClicked();

    /**
     * @brief addRoomTextChanged: Slot utilizzato per la gestione dell'abilitazione del pulsante aggiungi stanza
     * @param text: testo di aggiungiStanza
     */
    void addRoomTextChanged(const QString& text);

private:

    /**
     * @brief raiseProblemDialog: Metodo utilizzato per la creazione della finestra dialog per eventiali problemi
     * @param labText
     */
    void raiseProblemDialog(const QString& labText);

    //campi per l'uente
    QLineEdit *name;
    QTextEdit *description;
    QComboBox *room;
    QComboBox *device;
    QLineEdit *aggiungiStanza;

    QDialog *Problem;
    QVBoxLayout *LProblem;
    QLabel *labelText;

    QVBoxLayout *Vlayout;
    QFormLayout *formLayout;

    QPushButton *addRoom;
    QHBoxLayout *racchiudiStanza;
};

#endif // ADDITEMWINDOW_H
