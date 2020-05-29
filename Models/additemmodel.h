#ifndef ADDITEMMODEL_H
#define ADDITEMMODEL_H


#include <QList>
#include <QString>

#include "Entities/bulb.h"

class additemmodel
{
public:
    additemmodel();

    QList<QString> *camere;
    QList<Bulb> *lampadina;

public slots:
    /**
     * @brief insert: utilizzato per inserire la nuova stanza
     */
    void insert(QString*);
};

#endif // ADDITEMMODEL_H
