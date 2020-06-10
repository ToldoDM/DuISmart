#ifndef THERMOSTATSETTINGS_H
#define THERMOSTATSETTINGS_H

#include "devicesettings.h"
#include <QLCDNumber>
#include <QPushButton>
#include <QIcon>
#include <QPixmap>

class thermostatSettings : public Settings
{
    Q_OBJECT
public:
    thermostatSettings(Settings *parent=nullptr);
private:
    QPushButton *increase;
    QPushButton *decrease;
    QLCDNumber *num ;
private slots:

    void displayIncreased();

    void displayDecreased();
};

#endif // THERMOSTATSETTINGS_H
