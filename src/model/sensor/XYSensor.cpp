#include "XYSensor.h"
namespace model{
    namespace sensor{
        //sensore nuovo
        XYSensor::XYSensor(QString name) : AbstractSensor(name){}
        //sensore importato dal json
        XYSensor::XYSensor(QString name,unsigned int id) : AbstractSensor(name,id){}
        void XYSensor::simulate() {
            x.clear();
            x.squeeze();
            y.clear();
            y.squeeze();
            int iterations = 11; //Upper bound-lower bound +1
            for (int i = 0; i < iterations; ++i){
                x.append(rand()%11);
                std::sort(x.begin(), x.end());
                y.append(rand()%101);
            }
        }
        const QList<float>& XYSensor::getX() const { return x; }
        const QList<float>& XYSensor::getY() const { return y; }
        void XYSensor::accept(SensorVisitorInterface& visitor){
            visitor.visitXYSensor(this);
        }
    }
}