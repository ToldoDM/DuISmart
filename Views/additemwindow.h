#ifndef ADDITEMWINDOW_H
#define ADDITEMWINDOW_H


#include <QFormLayout>
#include <QErrorMessage>
#include <QDialog>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QDialogButtonBox>
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

    ~AddItemWindow() override;

    /**
     * @brief AddItemWindow: Costruttore di copia
     */
    AddItemWindow(const AddItemWindow&);

    /**
     * @brief operator =: Operatore di assegnazione
     * @return
     */
    AddItemWindow& operator=(const AddItemWindow&);

    /**
     * @brief populateRoomsComboBox: Aggiunge alla combo box le camere attualmente presenti
     * @param list: lista camere
     */
    void populateRoomsComboBox(QList<const QString*>* list);

protected:

    /**
     * @brief closeEvent: Evento generato alla chiusura della finestra
     */
    void closeEvent(QCloseEvent *) override;

signals:

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

    /**
     * @brief closeAddItemW: Evento generato alla chiusura della finestra
     */
    void closeAddItemW();


private slots:

    /**
     * @brief getChanges: Slot usato per il segnale proveniente dal textChanged di description
     */
    void getChanges(const QString&);

    /**
     * @brief accept: Accettazione campi nuovo elemento
     */
    void accept() override;

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
    QComboBox *room;
    QComboBox *device;
    QLineEdit *aggiungiStanza;

    QVBoxLayout *Vlayout;
    QFormLayout *formLayout;

    QPushButton *addRoom;
    QHBoxLayout *racchiudiStanza;
    QDialogButtonBox *buttonBox;
};

#endif // ADDITEMWINDOW_H
