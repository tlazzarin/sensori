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
                const QList<AbstractSensor*>& search(QString query) const;
                void insert(AbstractSensor* new_sensor);
                void remove(quint32 key); //cancellazione deep del sensore
                AbstractSensor* get(quint32 key) const; //se non lo trova ritorna nullptr, non ritorna un const AbstractSensor& perché dovrà farci le simulazioni che vanno a modificare l'oggetto
        };
    }
}
#endif