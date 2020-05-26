#include "settingsbutton.h"

SettingsButton::SettingsButton(QWidget *parent) : CustomButton(parent){
    ico = QIcon(":Images/setting.png");
    icoOver = QIcon(":Images/setting_over.png");
    setIconSize(QSize(30,30));
}

SettingsButton::~SettingsButton() = default;

void SettingsButton::enterEvent(QEvent *event){
    CustomButton::enterEvent(event);
    setIcon(icoOver);
}

void SettingsButton::leaveEvent(QEvent *event){
    CustomButton::leaveEvent(event);
    setIcon(ico);
}
