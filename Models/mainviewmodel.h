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

    /**
     * @brief MainViewModel: Ridefinizione costruttore di copia
     */
    MainViewModel(const MainViewModel&);


    ~MainViewModel();

    MainViewModel& operator=(const MainViewModel&);

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
    void addRoom(const QString *newRoom);

    /**
     * @brief removeRoom: Metodo utilizzato per rimuovere una stanza dalla lista delle stanze disponibili
     * @param roomName: nome stanza
     */
    void removeRoom(const QString& roomName);

    /**
     * @brief getRoomList: Ritorna il puntatore alla lista contenente le camere
     * @return lista contenente le camere
     */
    QList<const QString*>* getRoomList() const;

    /**
     * @brief setDeviceSettings: Imposta i setting del device indicato
     * @param data: setting data
     */
    void setDeviceSettings(const SettingData& data);

    /**
     * @brief getDeviceSettings: Ottiene i setting del device indicato
     * @param devId: Id device
     */
    SettingData* getDeviceSettings(int devId) const;

private:

    /**
     * @brief rooms: Stanze presenti
     */
    QList<const QString*>* rooms;

    /**
     * @brief deviceList: Lista device
     */
    CVector<const SmartDevice*> deviceList;
};

#endif // MAINVIEWMODEL_H
