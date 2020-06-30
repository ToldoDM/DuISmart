#ifndef BASEMODEL_H
#define BASEMODEL_H

#include<QObject>

class BaseModel : public QObject
{
public:
    /**
     * @brief BaseModel Costruttore di default
     */
    explicit BaseModel();

    /**
     * @brief BaseModel: Costruttore di copia
     */
    BaseModel(const BaseModel&);

    /**
     * @brief operator=: Ridefinizione assegnazione
     * @return
     */
    BaseModel& operator=(const BaseModel&);

    /**
     * @brief ~BaseModel: Distruttore
     */
    virtual ~BaseModel() = 0;
};

#endif // BASEMODEL_H
