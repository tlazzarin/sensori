#ifndef MODEL_SENSOR_ABSTRACTSENSOR_H
#define MODEL_SENSOR_ABSTRACTSENSOR_H
#include <QString>
#include <QtTypes>
#include <QRandomGenerator>
namespace model
{
    namespace sensor
    {
        class AbstractSensor
        {
        private:
            quint32 id; //genera un intero di 32-bit senza segno https://doc.qt.io/qt-6/qttypes.html#quint32-typedef
            QString name;

        protected:
            explicit AbstractSensor(QString name); //sensore nuovo
            explicit AbstractSensor(QString name,quint32 id); //sensore importato dal json
        public:
            const quint32& getId() const;
            const QString& getName() const;
            void setName(const QString name);
            virtual ~AbstractSensor() = default;
            virtual void simulate() = 0;
        };
    }
}

#endif