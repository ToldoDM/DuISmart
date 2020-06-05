#ifndef BULBSETTINGS_H
#define BULBSETTINGS_H

#include "devicesettings.h"
#include <QLCDNumber>
#include <QSlider>

#include <QVBoxLayout>

enum BulbColor{
    Red=0,
    Orange=1,
    Yellow=2,
    Green=3,
    Blue=4,
    Indigo=5,
    Violet=6
};

class BulbSettings : public Settings
{
public:
    explicit BulbSettings(Settings *parent=nullptr);

private:
    QLCDNumber *lcdBulb;
    QSlider *sliderBulb;

private slots:
    void setValue(int value);

signals:
    void ValueChanged(int actualValue);

};

#endif // BULBSETTINGS_H
