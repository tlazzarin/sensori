TEMPLATE = app
TARGET = Sensori
INCLUDEPATH += .
#Qt
QT+= core widgets
CONFIG += c++17
CONFIG += debug
CONFIG += console

# Input
HEADERS += \

SOURCES += \
        main.cpp \

#Fontawesome Icons
CONFIG+=fontAwesomeFree
include(lib/QtAwesome/QtAwesome.pri)
RC_ICONS = assets/chart-line-solid.ico