#ifndef BULBSETTINGS_H
#define BULBSETTINGS_H

#include "devicesettings.h"
#include <QLCDNumber>
#include <QSlider>
#include <QColorDialog>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>


class BulbSettings : public DeviceSettings
{
    Q_OBJECT
public:

    explicit BulbSettings(int devId);

    ~BulbSettings();

    /**
     * @brief setCurrentSettings: Imposta i dati correnti all'apertura della finestra
     */
    virtual void setCurrentSettings(const SettingData&) override;

protected:
    QPushButton *selectColor;

    QLCDNumber *lcdBulb;

    QColorDialog *cDialog;

    QSlider *sliderBulb;

    QGridLayout *setBulb;
    QVBoxLayout *encase;

protected slots:

    /**
     * @brief setSettings: Slot utilizzato per gestire le modifiche da parte della finestra settings
     */
    virtual void setSettings() const override;


private slots:

    /**
     * @brief pressedSelectColor: segnale per aprire dialogo selezione colore
     */
    void pressedSelectColor() const;

    /**
     * @brief SelectedColor: segnale colore selezionato per bulb
     */
    void bulbSelectedColor();
};

#endif // BULBSETTINGS_H
