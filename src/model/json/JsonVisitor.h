#ifndef MODEL_JSON_JSONVISITOR_H
#define MODEL_JSON_JSONVISITOR_H
// Qt (model)
#include <QJsonObject>
#include <QJsonArray>
// Model
#include "model/sensor/SensorVisitorInterface.h"
#include "model/sensor/QuantitySensor.h"
#include "model/sensor/EventSensor.h"
#include "model/sensor/XYSensor.h"

using namespace model::sensor;
namespace model::json
{
    class JsonVisitor : public SensorVisitorInterface
    {
    private:
        QJsonObject *sensorObj;

    public:
        QJsonObject *getSensorObj();
        virtual void visitQuantitySensor(QuantitySensor *qs);
        virtual void visitEventSensor(EventSensor *es);
        virtual void visitXYSensor(XYSensor *xys);
    };
}

#endif