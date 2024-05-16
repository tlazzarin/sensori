#include "DB.h"
#include <QDebug>
using namespace model::sensor;
namespace model
{
    namespace database
    {
        void DB::insert(AbstractSensor *new_sensor)
        {
            sensors.append(new_sensor);
        }
        void DB::remove(unsigned int key)
        {
            AbstractSensor *sensor;
            for (int i = 0; i < sensors.size(); i++)
            {
                sensor = sensors.at(i);
                if (sensor->getId() == key)
                {
                    delete sensor;
                    sensors.removeAt(i);
                    break;
                }
            }
        }
        AbstractSensor* DB::get(unsigned int key) const{
            for (int i = 0; i < sensors.size(); i++)
            {
                if (sensors.at(i)->getId() == key)
                {
                    return sensors.at(i);
                    break;
                }
            }
            return nullptr;
        }
        QList<AbstractSensor*> DB::search(const QString& query) const{
            //Se l'utente non ha fatto alcuna ricerca ritorna tutti i sensori
            if(query=="") return sensors;
            QList<AbstractSensor*> out;
            //Controllo se in ogni id e nome del sensore è presente il contenuto della query
            for (auto sensor:sensors)
            {
                if(QString::number(sensor->getId()).contains(query) || sensor->getName().contains(query)){
                    out.append(sensor);
                }
            }
            return out;
        }

        unsigned int DB::getLastSensorId() const{
            if(sensors.size()>= 1)
                return sensors.last()->getId();
            else return 0;
        }

        unsigned int DB::getFirstSensorId() const{
            if(sensors.size()>= 1)
                return sensors.first()->getId();
            else return 0;
        }

        void DB::saveToFile(const QString& path){
            qDebug()<<"Path: "<<path;
            QJsonArray mainArray;
            for(auto sensor:sensors){
                sensor->accept(visitor);
                mainArray.push_back(*(visitor.getSensorObj()));
                qDebug()<<visitor.getSensorObj()[0];
            }
            QJsonDocument document(mainArray);
            QFile file(path);
            file.open(QIODevice::WriteOnly);
            file.write(document.toJson());
            file.close();
        }
    }
}