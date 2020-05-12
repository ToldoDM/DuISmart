#ifndef DEVICELISTITEM_H
#define DEVICELISTITEM_H

#include <QPushButton>
#include <QBoxLayout>
#include <QLabel>

class DeviceListItem : public QWidget
{

public:
    DeviceListItem(QWidget *parent = nullptr);

private:
    QPushButton *button;
    QLabel *label;
    QHBoxLayout *hlay;
};

#endif // DEVICELISTITEM_H
