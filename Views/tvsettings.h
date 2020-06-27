#ifndef DISPLAYSETTINGS_H
#define DISPLAYSETTINGS_H

#include "devicesettings.h"

#include <QLCDNumber>
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QPushButton>


class TvSettings : public DeviceSettings
{
    Q_OBJECT
public:
    TvSettings(int idDevice);

    ~TvSettings();

    /**
     * @brief setCurrentSettings: Imposta i dati correnti all'apertura della finestra
     */
    virtual void setCurrentSettings(const SettingData&) override;

protected slots:

    /**
     * @brief setSettings: Slot utilizzato per gestire le modifiche da parte della finestra settings
     */
    virtual void setSettings() const override;

protected:

    //campi per il contrasto
    QLCDNumber *lcdCont;
    QSlider *sliderCont;

    //campi per la luminosita
    QLCDNumber *lcdBright;
    QSlider *sliderBright;

    QSpinBox *spinBox;

    //layout
    QGridLayout *setDisplay;
    QVBoxLayout *vlay;
    QHBoxLayout *chHLay;
    QPushButton *Channel;

};

#endif // DISPLAYSETTINGS_H
