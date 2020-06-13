#-------------------------------------------------
#
# Project created by QtCreator 2020-04-09T16:14:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DuISmart
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        Entities/bulb.cpp \
        Entities/display.cpp \
        Entities/listdevice.cpp \
        Entities/smartdevice.cpp \
    Entities/thermostat.cpp \
    Entities/tv.cpp \
    Exceptions/argumentexception.cpp \
        Models/basemodel.cpp \
        Models/mainviewmodel.cpp \
        Models/additemmodel.cpp \
        Views/CustomItems/bulblistitem.cpp \
    Views/CustomItems/custombutton.cpp \
        Views/CustomItems/devicelistitem.cpp \
        Views/CustomItems/onoffbutton.cpp \
    Views/CustomItems/settingsbutton.cpp \
    Views/CustomItems/thermolistitem.cpp \
    Views/CustomItems/tvlistitem.cpp \
    Views/additemwindow.cpp \
        Views/mainwindow.cpp \
        controller.cpp \
        main.cpp \
    Views/devicesettings.cpp \
    Views/bulbsettings.cpp \
    Views/displaysettings.cpp \
    Views/thermostatsettings.cpp \
    txtmanager.cpp


HEADERS += \
    Entities/thermostat.h \
    Entities/tv.h \
    Enums/RoomType.h \
        Enums/devicestate.h \
        Entities/bulb.h \
        Entities/display.h \
        Entities/listdevice.h \
        Entities/smartdevice.h \
    Enums/devicetype.h \
    Exceptions/argumentexception.h \
        Models/basemodel.h \
        Models/mainviewmodel.h \
        Views/CustomItems/bulblistitem.h \
    Views/CustomItems/custombutton.h \
        Views/CustomItems/devicelistitem.h \
        Views/CustomItems/onoffbutton.h \
    Views/CustomItems/settingsbutton.h \
    Views/CustomItems/thermolistitem.h \
    Views/CustomItems/tvlistitem.h \
    Views/additemwindow.h \
        Views/mainwindow.h \
        controller.h \
    Models/additemmodel.h \
    Views/devicesettings.h \
    Views/bulbsettings.h \
    Views/displaysettings.h \
    Views/thermostatsettings.h \
    txtmanager.h

FORMS +=

DISTFILES +=

RESOURCES += \
    resources.qrc
