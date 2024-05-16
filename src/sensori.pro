TEMPLATE = app
TARGET = Sensori
INCLUDEPATH += .
#Qt
QT+= core widgets charts
CONFIG += c++17 debug console

# Input
HEADERS += \
        model/sensor/AbstractSensor.h \
        model/sensor/QuantitySensor.h \
        model/sensor/EventSensor.h \
        model/sensor/XYSensor.h \
        model/sensor/SensorVisitorInterface.h \
        model/database/DB.h \
        model/json/JsonVisitor.h \
        view/MainWindow.h \
        view/NewSensorWizard.h \
        view/BrowserWidget.h \
        view/SensorCardWidget.h \
        view/SensorsListWidget.h \
        view/sensorViewer/SensorInspectorWidget.h \
        view/sensorViewer/SensorControlWidget.h \
        view/sensorViewer/SensorVisitor.h \
        view/sensorViewer/SensorRenameWidget.h \

SOURCES += \
        main.cpp \
        model/sensor/AbstractSensor.cpp \
        model/sensor/QuantitySensor.cpp \
        model/sensor/EventSensor.cpp \
        model/sensor/XYSensor.cpp \
        model/database/DB.cpp \
        model/json/JsonVisitor.cpp \
        view/MainWindow.cpp \
        view/NewSensorWizard.cpp \
        view/BrowserWidget.cpp \
        view/SensorCardWidget.cpp \
        view/SensorsListWidget.cpp \
        view/sensorViewer/SensorInspectorWidget.cpp \
        view/sensorViewer/SensorControlWidget.cpp \
        view/sensorViewer/SensorVisitor.cpp \
        view/sensorViewer/SensorRenameWidget.cpp \

#Fontawesome Icons
CONFIG+=fontAwesomeFree
include(lib/QtAwesome/QtAwesome.pri)
RC_ICONS = assets/chart-line-solid.ico