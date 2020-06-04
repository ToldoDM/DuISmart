#include "additemmodel.h"

#include <QDialog>
#include <QVBoxLayout>


AddItemModel::AddItemModel(QList<const QString*> *list){

    // lista camere che verranno prese/passate dal mainVM
    camere = list;

    deviceName = tr("Device name");
    friendlyName = tr("Device description");
}

void AddItemModel::insert(const QString& s){
    //mettere controllo di stanza già presenti nella possibile lista
    camere->append(&s);
}


void AddItemModel::setDName(const QString &s){ deviceName = s; }

void AddItemModel::setFName(const QString &s){ friendlyName = s; }
