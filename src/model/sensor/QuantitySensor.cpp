#include "QuantitySensor.h"
namespace model
{
    namespace sensor
    {
        QuantitySensor::QuantitySensor(QString name) : AbstractSensor(name), val(0) {}
        QuantitySensor::QuantitySensor(QString name,unsigned int id) : AbstractSensor(name,id), val(0) {}
        void QuantitySensor::simulate() {
            val=rand()%1001;
        }
        const int& QuantitySensor::getVal() const { return val; }
        void QuantitySensor::setVal(int val) {
            if (val < 1 || val > 1000)
                val=0;
            this->val = val;
        }
        void QuantitySensor::accept(SensorVisitorInterface& visitor){
            visitor.visitQuantitySensor(this);
        }
    }
}