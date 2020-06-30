#ifndef CLOSEBUTTON_H
#define CLOSEBUTTON_H

#include <QToolButton>
#include "Views/CustomItems/custombutton.h"
#include <QLabel>
#include <QMouseEvent>


class CloseButton : public CustomButton
{
public:
    explicit CloseButton(QWidget *parent=nullptr);

    void setCloseIcons(const QString& IconStd, const QString& onOver);

    virtual ~CloseButton() override;

    /**
     * @brief OnOffButton: Costruttore di copia
     */
    CloseButton(const CloseButton&);

    /**
     * @brief operator=: Operatore di assegnazione
     * @return
     */
    CloseButton& operator=(const CloseButton&);


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
     * @brief IconStd: icona standard / Icona pulsante off mouse over
     */
    QIcon IconStd;

    /**
     * @brief onOver: Icona pulsante on mouse over
     */
    QIcon onOver;

};

#endif // CLOSEBUTTON_H
