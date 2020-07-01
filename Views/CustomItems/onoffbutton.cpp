#include "onoffbutton.h"

OnOffButton::OnOffButton(DeviceState actualState, QWidget *parent) : CustomButton(parent), state(actualState) {
    setIcon(state == DeviceState::Off ? offIco : onIco);
    setIconSize(QSize(100,100));
}

OnOffButton::~OnOffButton() = default;

void OnOffButton::mousePressEvent(QMouseEvent *mEvent){
    CustomButton::mousePressEvent(mEvent);
    if(mEvent->buttons() == Qt::LeftButton){
        //se e' stato premuto il bottone sx allora cambio icona e lancio l'evento
        state = (state == DeviceState::Off ? DeviceState::On : DeviceState::Off);
        setIcon(state == DeviceState::Off ? offIco : onIco);
        emit onChangeState(state);
    }
}

OnOffButton::OnOffButton(const OnOffButton& oof) : CustomButton(oof){
    state = oof.state;
    this->onIco = QIcon(oof.onIco);
    this->offIco = QIcon(oof.offIco);
    this->onOver = QIcon(oof.onOver);
    this->offOver = QIcon(oof.offOver);
    setIcon(state == DeviceState::Off ? offIco : onIco);
    setIconSize(QSize(100,100));
}

OnOffButton& OnOffButton::operator=(const OnOffButton &oof){
    CustomButton::operator=(oof);
    if(this != & oof){
        state = oof.state;
        this->onIco = QIcon(oof.onIco);
        this->offIco = QIcon(oof.offIco);
        this->onOver = QIcon(oof.onOver);
        this->offOver = QIcon(oof.offOver);
        setIcon(state == DeviceState::Off ? offIco : onIco);
        setIconSize(QSize(100,100));
    }
    return *this;
}

void OnOffButton::enterEvent(QEvent *event){
    CustomButton::enterEvent(event);
    setIcon(state == DeviceState::Off ? offOver : onOver);
}

void OnOffButton::leaveEvent(QEvent *event){
    CustomButton::leaveEvent(event);
    setIcon(state == DeviceState::Off ? offIco : onIco);
}

void OnOffButton::setOnOffIcons(const QString &onIco, const QString &offIco, const QString &onOver, const QString &offOver){
    this->onIco = QIcon(QPixmap(onIco));
    this->offIco = QIcon(QPixmap(offIco));
    this->onOver = QIcon(QPixmap(onOver));
    this->offOver = QIcon(QPixmap(offOver));
    setIcon(state == DeviceState::Off ? this->offIco : this->onIco);
}
