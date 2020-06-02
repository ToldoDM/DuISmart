#ifndef ADDITEMMODEL_H
#define ADDITEMMODEL_H


#include <QList>
#include <QString>
#include "basemodel.h"
#include "Entities/bulb.h"
#include "Enums/devicetype.h"

class AddItemModel: public BaseModel
{
    Q_OBJECT
public:
    explicit AddItemModel();

    QList<QString> *camere;
    QList<SmartDevice*> *devList;

    /**
     * @brief deviceName: Nome device
     */
    QString deviceName;

    /**
     * @brief friendlyName: Nome friendly
     */
    QString friendlyName;

public slots:
    /**
     * @brief insert: utilizzato per inserire la nuova stanza
     */
    void insert(const QString& s);

};

#endif // ADDITEMMODEL_H
