#include "txtmanager.h"

TxtManager::TxtManager(){

    nameFile = new QFile(":/IOFile.txt3");
}

void TxtManager::writeData(DeviceType type,int id, QString roomName){

    //append = informazioni scritte alla fine del file in modo che non venga sovrascritto
    if(nameFile->open(QIODevice::WriteOnly/* | QIODevice::Append */| QIODevice::Text))
          {
              QTextStream out(nameFile);
              out<<"type"<<" "<<"id"<<" "<<"roomName"<<" "/*<<descript<<" "<<state*/<<"'\n";
          }

    nameFile->close();
}
