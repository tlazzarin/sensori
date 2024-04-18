#include "QuantitySensor.h"
#include <QRandomGenerator>
namespace model
{
    namespace sensor
    {
        QuantitySensor::QuantitySensor(QString id, QString name, int value) : AbstractSensor(id, name), val(value) {}
        void QuantitySensor::simulate() {
            val=QRandomGenerator::global()->bounded(0,101);
        }
        int QuantitySensor::getVal() const { return val; }
        void QuantitySensor::setVal(int val) {
            if (val < 1 || val > 100)
                val=0;
            this->val = val;
        }
    }
}