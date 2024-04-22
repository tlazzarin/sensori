#include "QuantitySensor.h"
namespace model
{
    namespace sensor
    {
        QuantitySensor::QuantitySensor(QString name) : AbstractSensor(name), val(0) {}
        QuantitySensor::QuantitySensor(QString name,quint32 id) : AbstractSensor(name,id), val(0) {}
        void QuantitySensor::simulate() {
            val=QRandomGenerator::global()->bounded(0,101);
        }
        const int& QuantitySensor::getVal() const { return val; }
        void QuantitySensor::setVal(int val) {
            if (val < 1 || val > 100)
                val=0;
            this->val = val;
        }
    }
}