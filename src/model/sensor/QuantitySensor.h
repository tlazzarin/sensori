#ifndef MODEL_SENSOR_QUANTITYSENSOR_H
#define MODEL_SENSOR_QUANTITYSENSOR_H
#include <QString>
#include "AbstractSensor.h"
namespace model
{
    namespace sensor
    {
        class QuantitySensor : public AbstractSensor
        {
            private:
                unsigned int val;//[1,1000]
            public:
                explicit QuantitySensor(QString name); //per creazione da zero
                explicit QuantitySensor(QString name,unsigned int id, unsigned int value=0); //per import da json
                void simulate() override;
                const unsigned int& getVal() const;
                virtual void accept(SensorVisitorInterface& visitor);
        };
    }
}
#endif