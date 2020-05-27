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

class AddItem : public QDialog
{
    Q_OBJECT
public:
    explicit AddItem(QDialog *parent=nullptr);

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

    /**
     * @brief insert: utilizzato per inserire la nuova stanza
     */
    void insert();

private:
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
