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
                int val;//[1,100]
            public:
                explicit QuantitySensor(QString name); //per creazione da zero
                explicit QuantitySensor(QString name,quint32 id); //per import da json
                void simulate() override;
                const int& getVal() const;
                void setVal(int val);
        };
    }
}
#endif