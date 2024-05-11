#include "EventSensor.h"
namespace model{
    namespace sensor{
        //sensore nuovo
        EventSensor::EventSensor(QString name) : AbstractSensor(name), data{0,0,0,0,0,0,0} {}
        //sensore importato dal json
        EventSensor::EventSensor(QString name,unsigned int id) : AbstractSensor(name,id), data{0,0,0,0,0,0,0} {}
        void EventSensor::simulate() {
            for (int i = 0; i < 7; i++)
                data[i] = rand()%11;
        }
        const QList<int>& EventSensor::getData() const { return data; }
        void EventSensor::accept(SensorVisitorInterface& visitor){
            visitor.visitEventSensor(this);
        }
    }
}