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

class AddItem : public QWidget
{
    Q_OBJECT
public:
    explicit AddItem(QWidget *parent=nullptr);

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
    //campi per l'uente
    QLineEdit *name;
    QTextEdit *description;
    QComboBox *combo;
};

#endif // ADDITEM_H
