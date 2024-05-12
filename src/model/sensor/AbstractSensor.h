#ifndef MODEL_SENSOR_ABSTRACTSENSOR_H
#define MODEL_SENSOR_ABSTRACTSENSOR_H
#include <QString>
#include "SensorVisitorInterface.h"
namespace model
{
    namespace sensor
    {
        class AbstractSensor
        {
        private:
            unsigned int id; //genera un intero di 32-bit senza segno https://doc.qt.io/qt-6/qttypes.html#unsigned int-typedef
            QString name;

        protected:
            explicit AbstractSensor(QString name); //sensore nuovo
            explicit AbstractSensor(QString name,unsigned int id); //sensore importato dal json
        public:
            unsigned int getId() const;
            const QString& getName() const;
            void setName(const QString& name);
            virtual ~AbstractSensor() = default;
            virtual void simulate() = 0;
            virtual void accept(SensorVisitorInterface& visitor)=0;
        };
    }
}

#endif