#include "additemmodel.h"

#include <QDialog>
#include <QVBoxLayout>


additemmodel::additemmodel(QObject *parent): QObject(parent)
{
/*PROVA BULB, da utilizzare per gli oggetti*/
    lampadina = new  QList<Bulb>;
    Bulb b,c;
    lampadina->append(b);
    lampadina->append(c);

// lista camere da aggiungere
    camere=new QList<QString>;
    camere->append("inserire stanza");
    camere->append("Cucina");
    camere->append("Salotto");
    camere->append("Bagno");
    camere->append("Camera da letto");

}

void additemmodel::insert(const QString s){
    //mettere controllo di stanza già presenti nella possibile lista
    camere->append(s);
}
