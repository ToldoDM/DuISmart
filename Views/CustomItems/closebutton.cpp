#include "closebutton.h"

CloseButton::CloseButton(QWidget *parent) : CustomButton(parent){
  IconStd = QIcon(":/Images/close_std.png");
  onOver = QIcon(":Images/close_over.png");
  setIcon(IconStd);
  setIconSize(QSize(20,20));
}

CloseButton::~CloseButton() = default;

CloseButton::CloseButton(const CloseButton& cb) : CustomButton(cb){
    IconStd = QIcon(cb.IconStd);
    onOver = QIcon(cb.onOver);
    setIcon(IconStd);
    setIconSize(QSize(20,20));
}

CloseButton& CloseButton::operator=(const CloseButton &cb){
    CustomButton::operator=(cb);
    if(this != & cb){
        IconStd = QIcon(cb.IconStd);
        onOver = QIcon(cb.onOver);
        setIcon(IconStd);
        setIconSize(QSize(20,20));
    }
    return *this;
}

void CloseButton::enterEvent(QEvent *event){
  CustomButton::enterEvent(event);
  setIcon(onOver);
}

void CloseButton::leaveEvent(QEvent *event){
  CustomButton::leaveEvent(event);
  setIcon(IconStd);
}
