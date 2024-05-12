#include "AbstractSensor.h"
#include <cstdlib>
namespace model
{
    namespace sensor
    {
        //https://doc.qt.io/qt-6/qrandomgenerator.html#generate
        AbstractSensor::AbstractSensor(QString name,unsigned int id) : id(id),name(name) {}
        AbstractSensor::AbstractSensor(QString name) : id(rand()%10000000),name(name) {}
        unsigned int AbstractSensor::getId() const { return id; }
        const QString& AbstractSensor::getName() const { return name; }
        void AbstractSensor::setName(const QString& name) { this->name = name; }
    }
}