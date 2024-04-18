#include "AbstractSensor.h"
namespace model
{
    namespace sensor
    {
        AbstractSensor::AbstractSensor(QString id, QString name) : id(id), name(name) {}
        QString AbstractSensor::getId() const { return id; }
        QString AbstractSensor::getName() const { return name; }
        void AbstractSensor::setName(const QString name) { this->name = name; }
    }
}