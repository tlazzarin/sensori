#ifndef MODEL_SENSOR_XYSENSOR_H
#define MODEL_SENSOR_XYSENSOR_H
#include <QList>
#include "algorithm"
#include "EventSensor.h"

namespace model{
    namespace sensor{
        class XYSensor : public EventSensor{
            private:
                QList<int> y;
            public:
                explicit XYSensor(QString name); //sensore nuovo
                explicit XYSensor(QString name,unsigned int id, const QList<int>& xdata, const QList<int>& ydata); //sensore importato dal json
                void simulate() override;
                const QList<int>& getY() const;
                virtual void accept(SensorVisitorInterface& visitor);
        };
    }
}
#endif