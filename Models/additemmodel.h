#ifndef ADDITEMMODEL_H
#define ADDITEMMODEL_H


#include <QList>
#include <QString>

#include "Entities/bulb.h"

class additemmodel: public QObject
{
    Q_OBJECT
public:
    explicit additemmodel(QObject *parent=nullptr);

    QList<QString> *camere;
    QList<Bulb> *lampadina;


    /**
     * @brief ExtractData: estrazione dati di un particolare indice
     * @return : Qstring dato presente nell'indice passato come parametro
     */
    QString ExtractData(int);
    /**
     * @brief NumEl: numero elementi in
     * @return
     */
    int NumEl();

public slots:
    /**
     * @brief insert: utilizzato per inserire la nuova stanza
     */
    void insert(const QString s);

};

#endif // ADDITEMMODEL_H
