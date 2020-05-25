#include "onoffbutton.h"

OnOffButton::OnOffButton(DeviceState actualState, QWidget *parent) : QToolButton(parent), state(actualState) {
    onIco = QIcon(QPixmap(":Images/on.png"));
    offIco = QIcon(QPixmap(":Images/off.png"));
    onOver = QIcon(QPixmap(":Images/on_clicked.png"));
    offOver = QIcon(QPixmap(":Images/off_clicked.png"));
    setIcon(state == DeviceState::Off ? offIco : onIco);
    setIconSize(QSize(100,100));
    setToolButtonStyle(Qt::ToolButtonIconOnly);
    setStyleSheet("border: none");
}

void OnOffButton::mousePressEvent(QMouseEvent *mEvent){
    if(mEvent->buttons() == Qt::LeftButton){
        //se e' stato premuto il bottone sx allora cambio icona e lancio l'evento
        state = (state == DeviceState::Off ? DeviceState::On : DeviceState::Off);
        setIcon(state == DeviceState::Off ? offIco : onIco);
        emit onChangeState(state);
    }
}

void OnOffButton::enterEvent(QEvent *event){
    QToolButton::enterEvent(event);
    setIcon(state == DeviceState::Off ? offOver : onOver);
}

void OnOffButton::leaveEvent(QEvent *event){
    QToolButton::leaveEvent(event);
    setIcon(state == DeviceState::Off ? offIco : onIco);
}

