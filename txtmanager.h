#ifndef TXTMANAGER_H
#define TXTMANAGER_H

#include <iostream>
#include <fstream>


#include <QFile>
#include "Enums/devicetype.h"
#include "Enums/devicestate.h"
#include <QTextStream>


class TxtManager
{
public:
    TxtManager();

    /**
     * @brief writeData: funzione che permette di scrivere su file le informazione dell'oggetto
     */
    void writeData(DeviceType, int, QString/*, QString, DeviceState*/);


private:
    /**
     * @brief nameFile: file in cui verranno scritte e lette le modifiche
     */
    QFile *nameFile;


};

#endif // TXTMANAGER_H
