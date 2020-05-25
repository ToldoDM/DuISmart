#ifndef ONOFFBUTTON_H
#define ONOFFBUTTON_H

#include <QToolButton>
#include "Entities/CustomEnum.h"
#include <QLabel>
#include <QMouseEvent>

class OnOffButton : public QToolButton
{
    Q_OBJECT
public:
    /**
     * @brief OnOffButton: Costruttore di default
     * @param parent: Widget padre
     */
    OnOffButton(DeviceState actualState = DeviceState::Off, QWidget *parent = nullptr);

signals:
    /**
     * @brief onChangeState: Evento creato alla pressione del pulsante
     */
    void onChangeState(DeviceState);

protected:

    /**
     * @brief mousePressEvent: Gestione della pressione del pulsante
     * @param event: Evento mouse
     */
    virtual void mousePressEvent(QMouseEvent *mEvent) override;

private:

    /**
     * @brief state: Stato del device
     */
    DeviceState state;
};

#endif // ONOFFBUTTON_H
