#include "additemmodel.h"




additemmodel::additemmodel()
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

//void additemmodel::insert(QString *testo){
//    //mettere controllo di stanza già presenti nella possibile lista
//    camere->append(testo);
//}
