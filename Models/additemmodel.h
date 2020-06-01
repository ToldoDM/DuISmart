#ifndef ADDITEMMODEL_H
#define ADDITEMMODEL_H


#include <QList>
#include <QString>
#include "basemodel.h"
#include "Entities/bulb.h"

class AddItemModel: public BaseModel
{
    Q_OBJECT
public:
    explicit AddItemModel();

    QList<QString> *camere;
    QList<SmartDevice*> *devList;

public slots:
    /**
     * @brief insert: utilizzato per inserire la nuova stanza
     */
    void insert(const QString s);

};

#endif // ADDITEMMODEL_H
