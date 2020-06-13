#ifndef DISPLAYSETTINGS_H
#define DISPLAYSETTINGS_H

#include "devicesettings.h"

#include <QLCDNumber>
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>


class DisplaySettings : public Settings
{
    Q_OBJECT
public:
    DisplaySettings(Settings *parent=nullptr);
protected:
    //campi per il contrasto
    QLCDNumber *lcdCont;
    QSlider *sliderCont;

    //campi per la luminosita
    QLCDNumber *lcdBright;
    QSlider *sliderBright;

    QSpinBox *spinBox;

    //campo per il refresh-rate
    //QComboBox *refreshRate;


signals:
    /**
     * @brief displayExtractedData: segnale che permette di trasferire informazioni luminosità e contrasto
     */
    void displayExtractedData(int, int);

    /**
     * @brief setNewChannel: segnale emesso che permette di cambiare al canale int
     */
    void setNewChannel(int);

private slots:
    virtual void accept();

    /**
     * @brief newChannel: slot che serve per invio segnale nuovo canale
     */
    void newChannel();

};

#endif // DISPLAYSETTINGS_H
