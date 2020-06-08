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

    /**
     * @brief AddItemModel: Costruttore di default
     */
    explicit AddItemModel(QList<const QString*> *list);

    /**
     * @brief insert: utilizzato per inserire la nuova stanza
     */
    void insert(const QString& s);

    /**
     * @brief setDName: utilizzato per aggiornare il valore di deviceName
     */
    void setDName(const QString& s);

    /**
     * @brief setFName: utilizzato per aggiornare il valore friendlyName
     */
    void setFName(const QString& s);

    /**
     * @brief setFName: utilizzato per avere il valore friendlyName
     */
    const QString& getFName() const;

private:
    /**
     * @brief camere: Lista camere presenti
     */
    QList<const QString*> *camere;

    /**
     * @brief deviceName: Nome device
     */
    QString deviceName;

    /**
     * @brief friendlyName: Nome friendly
     */
    QString friendlyName;
};

#endif // ADDITEMMODEL_H
