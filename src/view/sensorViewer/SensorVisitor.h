#ifndef VIEW_SENSORVIEWER_SENSORVISITOR_H
#define VIEW_SENSORVIEWER_SENSORVISITOR_H
//Qt
#include <QWidget>
#include <QProgressBar>
//Model
#include "model/sensor/SensorVisitorInterface.h"
#include "model/sensor/QuantitySensor.h"
#include "model/sensor/EventSensor.h"
#include "model/sensor/XYSensor.h"

using namespace model::sensor;
namespace view{
    namespace sensorViewer{
        class SensorVisitor : public SensorVisitorInterface{
            private:
                QWidget* widget; //grafici o barra caricamento
            public:
                QWidget* getWidget();
                virtual void visitQuantitySensor(QuantitySensor* qs);
                virtual void visitEventSensor(EventSensor* es);
                virtual void visitXYSensor(XYSensor* xys);
        };
    }
}

#endif