#include "XYSensor.h"
namespace model{
    namespace sensor{
        //sensore nuovo
        XYSensor::XYSensor(QString name) : AbstractSensor(name){}
        //sensore importato dal json
        XYSensor::XYSensor(QString name,quint32 id) : AbstractSensor(name,id){}
        void XYSensor::simulate() {
            x.clear();
            x.squeeze();
            y.clear();
            y.squeeze();
            int iterations = QRandomGenerator::global()->bounded(5,21);
            for (int i = 0; i < iterations; i++){
                x.append(QRandomGenerator::global()->bounded(21.0));
                y.append(QRandomGenerator::global()->generateDouble());
            }
        }
        QList<float> XYSensor::getX() const { return x; }
        QList<float> XYSensor::getY() const { return y; }
    }
}