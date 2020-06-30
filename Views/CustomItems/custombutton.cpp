#include "custombutton.h"

CustomButton::CustomButton(QWidget *parent) : QToolButton(parent){
    setToolButtonStyle(Qt::ToolButtonIconOnly);
    setStyleSheet("border: none");
}

CustomButton::~CustomButton() = default;

CustomButton::CustomButton(const CustomButton&) {}

CustomButton& CustomButton::operator=(const CustomButton &) { return *this; }

void CustomButton::mousePressEvent(QMouseEvent *mEvent){
    //se e' stato premuto il bottone sx allora lancio l'evento
    if(mEvent->buttons() == Qt::LeftButton) emit onClicked();
}

void CustomButton::enterEvent(QEvent *event){
    QToolButton::enterEvent(event);
    emit onMouseEnter();
}

void CustomButton::leaveEvent(QEvent *event){
    QToolButton::leaveEvent(event);
    emit onMouseLeave();
}
