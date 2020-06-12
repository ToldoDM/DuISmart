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
#include <QColor>


class BulbSettings : public Settings
{
    Q_OBJECT
public:

    explicit BulbSettings(Settings *parent=nullptr);

protected:
    QPushButton *selectColor;

    QLCDNumber *lcdBulb;

    QColorDialog *cDialog;

    QSlider *sliderBulb;

    QColor *bulbColor;



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
    void selectedColor(const QColor);

signals:

    void extractedData(const QColor ,const int );
};

#endif // BULBSETTINGS_H
