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
            int iterations = rand()%(21-5+1); //Upper bound-lower bound +1
            for (int i = 0; i < iterations; i++){
                x.append(rand()%21);
                y.append((double)rand());
            }
        }
        const QList<float>& XYSensor::getX() const { return x; }
        const QList<float>& XYSensor::getY() const { return y; }
        void XYSensor::accept(SensorVisitorInterface& visitor){
            visitor.visitXYSensor(this);
        }
    }
}