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

signals:
    /**
     * @brief displayExtractedData: segnale che permette di trasferire informazioni luminosità e contrasto
     */
    void displayExtractedData(int, int);

    /**
     * @brief setNewChannel: segnale emesso che permette di cambiare al canale int
     */
    void setNewChannel(int,int);

private slots:
    virtual void accept();

    /**
     * @brief newChannel: slot che serve per invio segnale nuovo canale
     */
    void newChannel();

};

#endif // DISPLAYSETTINGS_H
