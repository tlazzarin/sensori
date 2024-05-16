#include "QuantitySensor.h"
namespace model
{
    namespace sensor
    {
        QuantitySensor::QuantitySensor(QString name) : AbstractSensor(name), val(0) {}
        QuantitySensor::QuantitySensor(QString name,unsigned int id, unsigned int value) : AbstractSensor(name,id), val(value) {}
        void QuantitySensor::simulate() {
            val=rand()%1001;
        }
        const unsigned int& QuantitySensor::getVal() const { return val; }
        void QuantitySensor::accept(SensorVisitorInterface& visitor){
            visitor.visitQuantitySensor(this);
        }
        void QuantitySensor::setVal(unsigned int newVal){val=newVal;}
    }
}