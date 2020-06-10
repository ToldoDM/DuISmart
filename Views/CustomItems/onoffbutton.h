#ifndef ONOFFBUTTON_H
#define ONOFFBUTTON_H

#include <QToolButton>
#include "Enums/devicestate.h"
#include "Views/CustomItems/custombutton.h"
#include <QLabel>
#include <QMouseEvent>

class OnOffButton : public CustomButton
{
    Q_OBJECT
public:
    /**
     * @brief OnOffButton: Costruttore di default
     * @param parent: Widget padre
     */
    explicit OnOffButton(DeviceState actualState = DeviceState::Off, QWidget *parent = nullptr);

    /**
     * @brief ~OnOffButton: Distruttore
     */
    virtual ~OnOffButton() override;

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

    /**
     * @brief enterEvent: Metodo chiamato quando il mouse entra dentro il widget
     * @param event: Evento generato
     */
    virtual void enterEvent(QEvent *event) override;

    /**
     * @brief leaveEvent: Metodo chiamato quando il mouse entra dentro il widget
     * @param event: Evento generato
     */
    virtual void leaveEvent(QEvent *event) override;

private:

    /**
     * @brief state: Stato del device
     */
    DeviceState state;

    /**
     * @brief onIco: Icona pulsante on
     */
    QIcon onIco;

    /**
     * @brief offIco: Icona pulsante off
     */
    QIcon offIco;

    /**
     * @brief onOver: Icona pulsante on mouse over
     */
    QIcon onOver;

    /**
     * @brief offOver: Icona pulsante off mouse over
     */
    QIcon offOver;
};

#endif // ONOFFBUTTON_H
