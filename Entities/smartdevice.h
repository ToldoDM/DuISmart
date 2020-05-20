#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H


class SmartDevice
{

public:
    /**
     * @brief SmartDevice: Costruttore di default
     */
    SmartDevice();

    /**
     * @brief ~SmartDevice: Distruttore virtuale puro
     */
    virtual ~SmartDevice() = 0;
};

#endif // SMARTDEVICE_H
