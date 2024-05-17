#include "XYSensor.h"
namespace model{
    namespace sensor{
        //sensore nuovo
        XYSensor::XYSensor(QString name) : EventSensor(name){}
        //sensore importato dal json
        XYSensor::XYSensor(QString name,unsigned int id, const QList<int>& xdata, const QList<int>& ydata) : EventSensor(name,id,xdata), y(ydata){}
        void XYSensor::simulate() {
            x.clear();
            x.squeeze();
            y.clear();
            y.squeeze();
            int iterations = 11; //Upper bound-lower bound +1
            for (int i = 0; i < iterations; ++i){
                x.append(i);
                y.append(rand()%101);
            }
        }
        const QList<int>& XYSensor::getY() const { return y; }
        void XYSensor::accept(SensorVisitorInterface& visitor){
            visitor.visitXYSensor(this);
        }
    }
}