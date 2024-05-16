#include "EventSensor.h"
namespace model{
    namespace sensor{
        //sensore nuovo
        EventSensor::EventSensor(QString name) : AbstractSensor(name){}
        //sensore importato dal json
        EventSensor::EventSensor(QString name,unsigned int id, const QList<int>& existingData) : AbstractSensor(name,id), data(existingData) {}
        void EventSensor::simulate() {
            data.clear();
            for (int i = 0; i < 7; i++)
                data.append(rand()%15);
        }
        const QList<int>& EventSensor::getData() const { return data; }
        void EventSensor::accept(SensorVisitorInterface& visitor){
            visitor.visitEventSensor(this);
        }
    }
}