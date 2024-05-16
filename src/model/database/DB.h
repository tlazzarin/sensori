#ifndef MODEL_DATABASE_DB_H
#define MODEL_DATABASE_DB_H
#include <QList>
#include <QJsonDocument>
#include <QFile>
#include "model/sensor/AbstractSensor.h"
#include "model/json/JsonVisitor.h"
using namespace model::sensor;
using namespace model::json;
namespace model{
    namespace database{
        class DB{
            private:
                QList<AbstractSensor*> sensors;
                JsonVisitor visitor;
                void clearList();
            public:
                QList<AbstractSensor*> search(const QString& query) const;
                void insert(AbstractSensor* new_sensor);
                void remove(unsigned int key); //cancellazione deep del sensore
                AbstractSensor* get(unsigned int key) const; //se non lo trova ritorna nullptr, non ritorna un const AbstractSensor& perché dovrà farci le simulazioni che vanno a modificare l'oggetto
                unsigned int getLastSensorId() const;
                unsigned int getFirstSensorId() const;
                void saveToFile(const QString& path);
                bool loadFromFile(const QString& path);
        };
    }
}
#endif