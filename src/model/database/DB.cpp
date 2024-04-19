#include "DB.h"
using namespace model::sensor;
namespace model
{
    namespace database
    {
        void DB::insert(AbstractSensor *new_sensor)
        {
            sensors.append(new_sensor);
        }
        void DB::remove(quint32 key)
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
        AbstractSensor* DB::get(quint32 key) const{
            for (int i = 0; i < sensors.size(); i++)
            {
                if (sensors.at(i)->getId() == key)
                {
                    return sensors.at(i);
                    break;
                }
            }
        }
        QList<AbstractSensor*> DB::search(QString query) const{
            if(query=="") return sensors;
        }
    }
}