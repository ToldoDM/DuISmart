#include "additemmodel.h"

#include <QDialog>
#include <QVBoxLayout>


AddItemModel::AddItemModel()
{
/*PROVA BULB, da utilizzare per gli oggetti*/
    devList = new  QList<SmartDevice*>;
    devList->append(new Bulb(0));
    devList->append(new Bulb(1));

// lista camere da aggiungere
    camere=new QList<QString>;
    camere->append("inserire stanza");
    camere->append("Cucina");
    camere->append("Salotto");
    camere->append("Bagno");
    camere->append("Camera da letto");

    deviceName = tr("Device name");
    friendlyName = tr("Device description");
}

void AddItemModel::insert(const QString& s){
    //mettere controllo di stanza già presenti nella possibile lista
    camere->append(s);
}
