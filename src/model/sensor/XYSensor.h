#ifndef MODEL_SENSOR_XYSENSOR_H
#define MODEL_SENSOR_XYSENSOR_H
#include <QList>
#include "algorithm"
#include "AbstractSensor.h"

namespace model{
    namespace sensor{
        class XYSensor : public AbstractSensor{
            private:
                QList<float> x;
                QList<float> y;
            public:
                explicit XYSensor(QString name); //sensore nuovo
                explicit XYSensor(QString name,unsigned int id); //sensore importato dal json
                void simulate() override;
                const QList<float>& getX() const;
                const QList<float>& getY() const;
                virtual void accept(SensorVisitorInterface& visitor);
        };
    }
}
#endif