#include "EventSensor.h"
namespace model{
    namespace sensor{
        //sensore nuovo
        EventSensor::EventSensor(QString name) : AbstractSensor(name), data{0,0,0,0,0,0,0} {}
        //sensore importato dal json
        EventSensor::EventSensor(QString name,quint32 id) : AbstractSensor(name,id), data{0,0,0,0,0,0,0} {}
        void EventSensor::simulate() {
            for (int i = 0; i < 7; i++)
                data[i] = QRandomGenerator::global()->bounded(0, 11);
        }
        const QList<int>& EventSensor::getData() const { return data; }
    }
}