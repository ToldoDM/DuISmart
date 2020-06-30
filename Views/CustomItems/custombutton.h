#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QToolButton>
#include <QLabel>
#include <QMouseEvent>


class CustomButton : public QToolButton
{
    Q_OBJECT
public:
    /**
     * @brief CustomButton: Costruttore di default
     * @param parent: Widget genitore
     */
    explicit CustomButton(QWidget *parent = nullptr);

    /**
     * @brief ~CustomButton: Distruttore
     */
    virtual ~CustomButton() override;

    /**
     * @brief OnOffButton: Costruttore di copia
     */
    CustomButton(const CustomButton&);

    /**
     * @brief operator=: Operatore di assegnazione
     * @return
     */
    CustomButton& operator=(const CustomButton&);

signals:
    /**
     * @brief onClicked: Evento genegato alla pressione del pulsante
     */
    void onClicked();

    /**
     * @brief onMouseEnter: Evento generato all'entrata del mouse nel pulsante
     */
    void onMouseEnter();

    /**
     * @brief onMouseLeave: Evento generato all'uscita del mouse dal pulsante
     */
    void onMouseLeave();


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
};

#endif // CUSTOMBUTTON_H
