#include "onoffbutton.h"

OnOffButton::OnOffButton(DeviceState actualState, QWidget *parent) : QToolButton(parent), state(actualState) {
    setIcon(QIcon(QPixmap(state == DeviceState::Off ? ":Images/off.png" : ":Images/on.png")));
    setIconSize(QSize(100,100));
    setToolButtonStyle(Qt::ToolButtonIconOnly);
    setStyleSheet("border: none");
}

void OnOffButton::mousePressEvent(QMouseEvent *mEvent){
    if(mEvent->buttons() == Qt::LeftButton){
        //se e' stato premuto il bottone sx allora cambio icona e lancio l'evento
        state = (state == DeviceState::Off ? DeviceState::On : DeviceState::Off);
        setIcon(QIcon(QPixmap(state == DeviceState::Off ? ":Images/off.png" : ":Images/on.png")));
        emit onChangeState(state);
    }
}

