#include "additemmodel.h"


AddItemModel::AddItemModel(QList<const QString*>* list){

    // lista camere che verranno prese/passate dal mainVM
    camere = list;

    deviceName = tr("Device name");
    friendlyName = tr("Device description");
}

void AddItemModel::insert(const QString& s){ camere->append(&s); }

void AddItemModel::setDName(const QString &s){ deviceName = s; }

void AddItemModel::setFName(const QString &s){ friendlyName = s; }

const QString& AddItemModel::getFName() const{ return friendlyName; }

