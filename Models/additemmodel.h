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

public slots:
    /**
     * @brief insert: utilizzato per inserire la nuova stanza
     */
    void insert(const QString s);

};

#endif // ADDITEMMODEL_H
