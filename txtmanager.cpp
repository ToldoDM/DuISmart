#include "txtmanager.h"

TxtManager::TxtManager(QObject *parent):QObject(parent){

    nameFile = new QFile(":/IOFile.txt");
}

void TxtManager::writeData(DeviceType type,int id, QString roomName){

    //append = informazioni scritte alla fine del file in modo che non venga sovrascritto
    if(nameFile->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
          {
              QTextStream out(nameFile);
              out<<"0"<<" "<<"111"<<" "<<"roomName"<<" "/*<<descript<<" "*/<<"'\n";
          }

    nameFile->close();
}


void TxtManager::readData()
{
    if (nameFile->open(QIODevice::ReadOnly | QIODevice::Text))
    {
       QTextStream in(nameFile);
       while (!in.atEnd())
       {
           //prende in considerazione la prima riga
          QString line = in.readLine();
          //divide la prima riga in stringhe divise da spazio
          QStringList splited = line.split(" ");
          emit readedData(/*static_cast<int>(splited.at(1)),*/splited.at(1),splited.at(2));
          //il primo dato viene ignorato in quanto IdCode
       }
       nameFile->close();
    }
}
