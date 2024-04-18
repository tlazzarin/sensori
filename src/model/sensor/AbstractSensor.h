#ifndef MODEL_SENSOR_ABSTRACTSENSOR_H
#define MODEL_SENSOR_ABSTRACTSENSOR_H
#include <QString>
namespace model
{
    namespace sensor
    {
        class AbstractSensor
        {
        private:
            QString id; // alfanumerico 8 caratteri
            QString name;

        protected:
            explicit AbstractSensor(QString id, QString name);
        public:
            QString getId() const;
            QString getName() const;
            void setName(const QString name);
            virtual ~AbstractSensor() = default;
            virtual void simulate() = 0;
        };
    }
}

#endif