#ifndef BASEMODEL_H
#define BASEMODEL_H

#include<QObject>

class BaseModel : public QObject
{
public:
    /**
     * @brief BaseModel Costruttore di default
     */
    BaseModel();

    /**
     * @brief ~BaseModel: Distruttore
     */
    virtual ~BaseModel() = 0;
};

#endif // BASEMODEL_H
