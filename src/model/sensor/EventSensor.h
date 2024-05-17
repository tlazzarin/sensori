#ifndef MODEL_SENSOR_EVENTSENSOR_H
#define MODEL_SENSOR_EVENTSENSOR_H
#include <QList>
#include "AbstractSensor.h"
namespace model
{
    namespace sensor
    {
        class EventSensor : public AbstractSensor{
        protected:
            QList<int> x;

        public:
            explicit EventSensor(QString name); //sensore nuovo
            explicit EventSensor(QString name,unsigned int id, const QList<int>& existingData); //sensore importato dal json
            void simulate() override;
            const QList<int>& getX() const;
            virtual void accept(SensorVisitorInterface& visitor);
        };
    }
}
#endif