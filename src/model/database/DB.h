#ifndef MODEL_DATABASE_DB_H
#define MODEL_DATABASE_DB_H
#include <QList>
#include "model/sensor/AbstractSensor.h"
using namespace model::sensor;
namespace model{
    namespace database{
        class DB{
            private:
                QList<AbstractSensor*> sensors;
            public:
                QList<AbstractSensor*> search(const QString& query) const;
                void insert(AbstractSensor* new_sensor);
                void remove(const unsigned int key); //cancellazione deep del sensore
                AbstractSensor* get(const unsigned int key) const; //se non lo trova ritorna nullptr, non ritorna un const AbstractSensor& perché dovrà farci le simulazioni che vanno a modificare l'oggetto
                unsigned int getLastSensorId() const;
        };
    }
}
#endif