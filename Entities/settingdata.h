#ifndef SETTINGDATA_H
#define SETTINGDATA_H


class SettingData{
public:

    SettingData(int Id) { devId = Id; }

    /**
     * @brief devId: device id di riferimento per le settings
     */
    int devId = 0;

    /**
     * @brief contrast: Contrasto
     */
    int contrast = 0;

    /**
     * @brief brightness: Luminosita'
     */
    int brightness = 0;

    /**
     * @brief channel: Canale Tv
     */
    int channel = 0;

    /**
     * @brief temp: Temperatura
     */
    int temp = 0;

    /**
     * @brief red: Range rosso
     */
    int red = 255;

    /**
     * @brief blue: Range blue
     */
    int blue = 255;

    /**
     * @brief green: Range verde
     */
    int green = 255;

};

#endif // SETTINGDATA_H
