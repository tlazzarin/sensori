#ifndef MODEL_SENSOR_XYSENSOR_H
#define MODEL_SENSOR_XYSENSOR_H
#include <QList>
#include "algorithm"
#include "AbstractSensor.h"

namespace model{
    namespace sensor{
        class XYSensor : public AbstractSensor{
            private:
                QList<int> x;
                QList<int> y;
            public:
                explicit XYSensor(QString name); //sensore nuovo
                explicit XYSensor(QString name,unsigned int id, const QList<int>& xdata, const QList<int>& ydata); //sensore importato dal json
                void simulate() override;
                const QList<int>& getX() const;
                const QList<int>& getY() const;
                virtual void accept(SensorVisitorInterface& visitor);
        };
    }
}
#endif