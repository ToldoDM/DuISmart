#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include "basemodel.h"
#include "Entities/listdevice.h"
#include <list>

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
    ListDevice getDevice(int deviceId) const;

    /**
     * @brief addDevice: Metodo per aggiungere un nuovo device alla lista
     * @param newDevice: Nuovo device da aggiungere
     */
    void addDevice(ListDevice newDevice) const;


private:
    /**
     * @brief deviceList: Lista device
     */
    std::list<ListDevice> deviceList;
};

#endif // MAINVIEWMODEL_H
