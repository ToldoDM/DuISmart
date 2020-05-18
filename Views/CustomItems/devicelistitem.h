#ifndef DEVICELISTITEM_H
#define DEVICELISTITEM_H

#include <QCheckBox>
#include <QBoxLayout>
#include <QLabel>

class DeviceListItem : public QWidget
{

public:
    DeviceListItem(QWidget *parent = nullptr);

private:
    QCheckBox *cbox;
    QLabel *deviceName, *friendlyName, *ico;
    QWidget *center;
    QHBoxLayout *hlay;
    QVBoxLayout *vlay;
};

#endif // DEVICELISTITEM_H
