#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include "basemodel.h"
#include "Entities/smartdevice.h"
#include <vector>


class MainViewModel : public BaseModel{

public:
    /**
     * @brief MainViewModel: Costruttore di default
     */
    MainViewModel();

    /**
     * @brief getDevice: Ritorna l'oggetto device richiesto
     * @param deviceId: id device di cui si vuole l'oggetto
     * @return
     */
    const SmartDevice* getDevice(int deviceId) const;

    /**
     * @brief addDevice: Metodo per aggiungere un nuovo device alla lista
     * @param newDevice: Nuovo device da aggiungere
     */
    void addDevice(SmartDevice* newDevice);


private:
    /**
     * @brief deviceList: Lista device
     */
    std::vector<const SmartDevice*> deviceList;
};

#endif // MAINVIEWMODEL_H
