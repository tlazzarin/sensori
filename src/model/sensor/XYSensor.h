#ifndef MODEL_SENSOR_XYSENSOR_H
#define MODEL_SENSOR_XYSENSOR_H
#include <QList>
#include "AbstractSensor.h"

namespace model{
    namespace sensor{
        class XYSensor : public AbstractSensor{
            private:
                QList<float> x;
                QList<float> y;
            public:
                explicit XYSensor(QString name); //sensore nuovo
                explicit XYSensor(QString name,quint32 id); //sensore importato dal json
                void simulate() override;
                QList<float> getX() const;
                QList<float> getY() const;
        };
    }
}
#endif