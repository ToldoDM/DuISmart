#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <QString>

class SmartDevice{

public:
    /**
     * @brief SmartDevice: Costruttore di default
     * @param devID: Id device
     */
    explicit SmartDevice(const int& devID, const QString& fName);

    /**
     * @brief ~SmartDevice: Distruttore virtuale puro
     */
    virtual ~SmartDevice() = 0;

    /**
     * @brief deviceId: Identificativo del device
     */
    int deviceId;

    /**
     * @brief friendlyName: Friendly name del device
     */
    QString friendlyName;

private:
};

#endif // SMARTDEVICE_H
