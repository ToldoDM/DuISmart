#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

class SmartDevice{

public:
    /**
     * @brief SmartDevice: Costruttore di default
     * @param devID: Id device
     */
    explicit SmartDevice(const int& devID);

    /**
     * @brief ~SmartDevice: Distruttore virtuale puro
     */
    virtual ~SmartDevice() = 0;

    /**
     * @brief deviceId: Identificativo del device
     */
    int deviceId;

private:
};

#endif // SMARTDEVICE_H
