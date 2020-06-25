#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include "basemodel.h"
#include "Entities/smartdevice.h"
#include "Entities/listdevice.h"
#include "Entities/cvector.h"


class MainViewModel : public BaseModel{

public:
    /**
     * @brief MainViewModel: Costruttore di default
     */
    explicit MainViewModel();

    ~MainViewModel();

    /**
     * @brief getDevice: Ritorna l'oggetto device richiesto
     * @param deviceId: id device di cui si vuole l'oggetto
     * @return
     */
    const SmartDevice* getDevice(int deviceId) const;

    /**
     * @brief removeDevice: Rimuove il device dalla lista
     * @param devId: Id del device da eliminare
     */
    void removeDevice(int devId);

    /**
     * @brief addDevice: Metodo per aggiungere un nuovo device alla lista
     * @param newDevice: Nuovo device da aggiungere
     */
    DeviceListItem* addDevice(SmartDevice* newDevice);

    /**
     * @brief addRoom: Metodo utilizzato per aggiungere una nuova stanza nella lista delle stanze
     * @param newRoom: Nome nuova stanza
     * @return Rirerimento costante della stringa appena aggiunta nella lista
     */
    void addRoom(const QString* newRoom);

    /**
     * @brief getRoomList: Ritorna il puntatore alla lista contenente le camere
     * @return lista contenente le camere
     */
    QList<const QString*>* getRoomList();

private:

    /**
     * @brief rooms: Stanze presenti
     */
    QList<const QString*> *rooms;

    /**
     * @brief deviceList: Lista device
     */
    CVector<const SmartDevice*> deviceList;
};

#endif // MAINVIEWMODEL_H
