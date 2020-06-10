#ifndef DISPLAYSETTINGS_H
#define DISPLAYSETTINGS_H

#include "devicesettings.h"

#include <QLCDNumber>
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>


class DisplaySettings : public Settings
{
    Q_OBJECT
public:
    DisplaySettings(Settings *parent=nullptr);

    //campi per il contrasto
    QLCDNumber *lcdCont;
    QSlider *sliderCont;

    //campi per la luminosita
    QLCDNumber *lcdBright;
    QSlider *sliderBright;

    //campo per il refresh-rate
    //QComboBox *refreshRate;

private:

signals:
    void displayExtractedData(int, int);

private slots:
    virtual void accept();

};

#endif // DISPLAYSETTINGS_H
