#ifndef SETTINGSBUTTON_H
#define SETTINGSBUTTON_H

#include "Views/CustomItems/custombutton.h"

class SettingsButton : public CustomButton
{
public:
    /**
     * @brief SettingsButton: Costruttore di default
     * @param parent: Widget genitore
     */
    explicit SettingsButton(QWidget *parent = nullptr);

    /**
     * @brief ~SettingsButton: Distruttore
     */
    virtual ~SettingsButton() override;

protected:
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
     * @brief ico: Icona setting
     */
    QIcon ico;

    /**
     * @brief icoOver: Icona setting over
     */
    QIcon icoOver;
};

#endif // SETTINGSBUTTON_H
