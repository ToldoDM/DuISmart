#ifndef THERMOSTATSETTINGS_H
#define THERMOSTATSETTINGS_H

#include "devicesettings.h"
#include <QLCDNumber>
#include <QPushButton>
#include <QIcon>

class ThermostatSettings : public Settings
{
    Q_OBJECT
public:
    ThermostatSettings(int idDevice,Settings *parent=nullptr);
protected:
    QPushButton *increase;
    QPushButton *decrease;
    QLCDNumber *num ;
    int idDevice;

signals:
    void ThermostatExtractedData(int,int);


private slots:

    void displayIncreased();

    void displayDecreased();

private slots:
    virtual void accept();
};

#endif // THERMOSTATSETTINGS_H
