#include "closebutton.h"

CloseButton::CloseButton(QWidget *parent) : CustomButton(parent){
  //IconStd = QIcon(":/Images/close_std.png");
  //onOver = QIcon(":Images/close_over.png");
  IconStd = QIcon(":/Images/close_std.png");
  onOver = QIcon(":Images/close_over.png");
  setIcon(IconStd);
  setIconSize(QSize(20,20));
}

CloseButton::~CloseButton() = default;

void CloseButton::enterEvent(QEvent *event){
  CustomButton::enterEvent(event);
  setIcon(onOver);
}

void CloseButton::leaveEvent(QEvent *event){
  CustomButton::leaveEvent(event);
  setIcon(IconStd);
}
