#ifndef BASEMODEL_H
#define BASEMODEL_H

#include<QObject>

class BaseModel : public QObject
{
    Q_OBJECT

signals:
    void refreshView();

public:
    /**
     * @brief BaseModel Costruttore di default
     * @param parent    widget genitore
     */
    BaseModel(QObject *parent = nullptr);
    virtual ~BaseModel() = 0;
};

#endif // BASEMODEL_H
