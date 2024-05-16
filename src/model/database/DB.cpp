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
        AbstractSensor *DB::get(unsigned int key) const
        {
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
        QList<AbstractSensor *> DB::search(const QString &query) const
        {
            // Se l'utente non ha fatto alcuna ricerca ritorna tutti i sensori
            if (query == "")
                return sensors;
            QList<AbstractSensor *> out;
            // Controllo se in ogni id e nome del sensore è presente il contenuto della query
            for (auto sensor : sensors)
            {
                if (QString::number(sensor->getId()).contains(query) || sensor->getName().contains(query))
                {
                    out.append(sensor);
                }
            }
            return out;
        }

        unsigned int DB::getLastSensorId() const
        {
            if (sensors.size() >= 1)
                return sensors.last()->getId();
            else
                return 0;
        }

        unsigned int DB::getFirstSensorId() const
        {
            if (sensors.size() >= 1)
                return sensors.first()->getId();
            else
                return 0;
        }

        void DB::saveToFile(const QString &path)
        {
            QJsonArray mainArray;
            for (auto sensor : sensors)
            {
                sensor->accept(visitor);
                mainArray.push_back(*(visitor.getSensorObj()));
            }
            QJsonDocument document(mainArray);
            QFile file(path);
            file.open(QIODevice::WriteOnly);
            file.write(document.toJson());
            file.close();
        }

        // Legge il file json e crea una QList che sostituisce quella del DB
        // Se l'inport va a buon fine ritorna true, altrimenti false
        bool DB::loadFromFile(const QString &path)
        {
            QFile file(path);
            file.open(QIODevice::ReadOnly);
            QString fileRead = file.readAll();
            file.close();
            QJsonDocument doc = QJsonDocument::fromJson(fileRead.toUtf8());
            if (doc.isNull())
                return false; // controlla se il json è ben formato
            QJsonArray mainArray = doc.array();
            QList<AbstractSensor *> newList;
            for (auto sensor : mainArray)
            {
                QJsonObject obj = sensor.toObject();
                // Per prima cosa controllo che siano presenti le proprietà name e id
                if (!obj.value("name").isUndefined() &&
                    !obj.value("id").isUndefined() &&
                    obj.value("id").toInt() != 0)
                {
                    //*EventSensor parsing
                    if (obj.value("type") == "EventSensor")
                    {
                        QList<int> data;
                        for (auto val : obj.value("values").toArray())
                            data.append(val.toInteger());
                        newList.append(new EventSensor(obj.value("name").toString(),
                                                       obj.value("id").toInt(),
                                                       data));
                    }
                    //*QuantitySensor parsing
                    else if (obj.value("type") == "QuantitySensor")
                    {
                        newList.append(new QuantitySensor(obj.value("name").toString(),
                                                          obj.value("id").toInt(),
                                                          obj.value("value").toInt()));
                    }
                    //*XYSensor parsing
                    // Prima di proseguire controllo se x e y hanno lo stesso numero di valori
                    else if (obj.value("type") == "XYSensor" &&
                             obj.value("x").toArray().size() == obj.value("y").toArray().size())
                    {
                        QList<int> x, y;
                        for (auto val : obj.value("x").toArray())
                            x.append(val.toInt());
                        for (auto val : obj.value("y").toArray())
                            y.append(val.toInt());
                        newList.append(new XYSensor(obj.value("name").toString(),
                                                    obj.value("id").toInt(),
                                                    x,
                                                    y));
                    }
                }
            }
            clearList();
            sensors = newList;
            return true;
        }

        // Deep delete dei sensori
        void DB::clearList()
        {
            for (auto sensor : sensors)
            {
                delete sensor;
            }
        }
    }
}