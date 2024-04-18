#ifndef MODEL_SENSOR_EVENTSENSOR_H
#define MODEL_SENSOR_EVENTSENSOR_H
#include "AbstractSensor.h"
namespace model
{
    namespace sensor
    {
        class EventSensor : public AbstractSensor
        {
            private:
            
        public:
            explicit EventSensor(QString id, QString name);
            void simulate() override;
        };
    }
}
#endif