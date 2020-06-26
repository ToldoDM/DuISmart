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

    explicit BulbSettings();

    ~BulbSettings();

protected:
    QPushButton *selectColor;

    QLCDNumber *lcdBulb;

    QColorDialog *cDialog;

    QSlider *sliderBulb;

    QColor *bulbColor;
    QGridLayout *setBulb;
    QVBoxLayout *encase;



private slots:
    //ridefinizione metodo virtuale di devicesettings?
    virtual void accept();

    /**
     * @brief pressedSelectColor: segnale per aprire dialogo selezione colore
     */
    void pressedSelectColor() const;

    /**
     * @brief SelectedColor: segnale colore selezionato per bulb
     */
    void bulbSelectedColor();

signals:

    void bulbExtractedData(const QColor& , int);
};

#endif // BULBSETTINGS_H
