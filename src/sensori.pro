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
        model/sensor/AbstractSensor.h \
        model/sensor/QuantitySensor.h \
        model/sensor/EventSensor.h \
        model/sensor/XYSensor.h \
        model/database/DB.h \

SOURCES += \
        main.cpp \
        model/sensor/AbstractSensor.cpp \
        model/sensor/QuantitySensor.cpp \
        model/sensor/EventSensor.cpp \
        model/sensor/XYSensor.cpp \
        model/database/DB.cpp

#Fontawesome Icons
CONFIG+=fontAwesomeFree
include(lib/QtAwesome/QtAwesome.pri)
RC_ICONS = assets/chart-line-solid.ico