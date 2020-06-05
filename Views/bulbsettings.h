#ifndef BULBSETTINGS_H
#define BULBSETTINGS_H

#include "devicesettings.h"
#include <QLCDNumber>
#include <QSlider>
#include <QColorDialog>
#include <QComboBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QColor>
#include <QPalette>

class BulbSettings : public Settings
{
    Q_OBJECT
public:
    explicit BulbSettings(Settings *parent=nullptr);

private:
    QLCDNumber *lcdBulb;
    QSlider *sliderBulb;
    QPushButton *selectColor;
    QColor *bulbColor;

private slots:
    //void UpdateValue(int);
    void changeColor(QWidget *button2);
    void pressedSelectColor();

signals:
    void ValueChanged(int);

};

#endif // BULBSETTINGS_H
