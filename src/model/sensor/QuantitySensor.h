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
                explicit QuantitySensor(QString id, QString name, int value=0);
                void simulate() override;
                int getVal() const;
                void setVal(int val);
        };
    }
}
#endif