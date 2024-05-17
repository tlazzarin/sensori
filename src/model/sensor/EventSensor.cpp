#include "EventSensor.h"
namespace model{
    namespace sensor{
        //sensore nuovo
        EventSensor::EventSensor(QString name) : AbstractSensor(name){}
        //sensore importato dal json
        EventSensor::EventSensor(QString name,unsigned int id, const QList<int>& existingData) : AbstractSensor(name,id), x(existingData) {}
        void EventSensor::simulate() {
            x.clear();
            for (int i = 0; i < 7; i++)
                x.append(rand()%15);
        }
        const QList<int>& EventSensor::getX() const { return x; }
        void EventSensor::accept(SensorVisitorInterface& visitor){
            visitor.visitEventSensor(this);
        }
    }
}