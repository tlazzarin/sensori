#include "AbstractSensor.h"
#include <QRandomGenerator>
namespace model
{
    namespace sensor
    {
        //https://doc.qt.io/qt-6/qrandomgenerator.html#generate
        AbstractSensor::AbstractSensor(QString name,quint32 id) : id(id),name(name) {}
        AbstractSensor::AbstractSensor(QString name) : id(QRandomGenerator::global()->bounded(1000000,9999999)),name(name) {}
        quint32 AbstractSensor::getId() const { return id; }
        QString AbstractSensor::getName() const { return name; }
        void AbstractSensor::setName(const QString name) { this->name = name; }
    }
}