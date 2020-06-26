#ifndef TXTMANAGER_H
#define TXTMANAGER_H

#include <iostream>
#include <fstream>


#include <QFile>
#include "Enums/devicetype.h"
#include "Enums/devicestate.h"
#include <QTextStream>

#include <QStringList>

class TxtManager : public QObject
{
    Q_OBJECT
public:
    TxtManager(QObject *parent=nullptr);

    /**
     * @brief writeData: funzione che permette di scrivere su file le informazione dell'oggetto
     */
    void writeData(DeviceType, int, QString/*, QString, DeviceState*/);

    /**
     * @brief readData: funzione per lettura dati su file
     */
    void readData();

private:
    /**
     * @brief nameFile: file in cui verranno scritte e lette le modifiche
     */
    QFile *nameFile;

signals:
    void readedData(const QString&, const QString&);

};

#endif // TXTMANAGER_H
