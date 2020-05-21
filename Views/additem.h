#ifndef ADDITEM_H
#define ADDITEM_H

//aggiunte per finestra
#include <QFormLayout>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QWidget>

//aggiunte per far girare il programma, controllare che non vengano chiamate anche in altre classi
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
     * @brief CancField: Eliminazione modifiche campi
     */
    void CancField();

private:
    //campi per l'uente
    QLineEdit *name;
    QTextEdit *description;
    QComboBox *combo;
};

#endif // ADDITEM_H
