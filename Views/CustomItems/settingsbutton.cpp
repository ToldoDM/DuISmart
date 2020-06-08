#include "settingsbutton.h"

SettingsButton::SettingsButton(QWidget *parent) : CustomButton(parent){
    ico = QIcon(":/Images/settings.png");
    icoOver = QIcon(":Images/settings_over.png");
    setIcon(ico);
    setIconSize(QSize(20,20));
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
