#ifndef SETTINGDATA_H
#define SETTINGDATA_H


class SettingData{
public:

    SettingData(int Id) { devId = Id; }

    /**
     * @brief devId: device id di riferimento per le settings
     */
    int devId;

    /**
     * @brief contrast: Contrasto
     */
    int contrast;

    /**
     * @brief brightness: Luminosita'
     */
    int brightness;

    /**
     * @brief channel: Canale Tv
     */
    int channel;

    /**
     * @brief temp: Temperatura
     */
    int temp;

    /**
     * @brief red: Range rosso
     */
    int red;

    /**
     * @brief blue: Range blue
     */
    int blue;

    /**
     * @brief green: Range verde
     */
    int green;

};

#endif // SETTINGDATA_H
