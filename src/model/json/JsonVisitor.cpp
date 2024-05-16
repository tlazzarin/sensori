#include "JsonVisitor.h"
namespace model::json
{
    QJsonObject *JsonVisitor::getSensorObj()
    {
        return sensorObj;
    }

    void JsonVisitor::visitEventSensor(EventSensor *es)
    {
        if(sensorObj!=nullptr) delete sensorObj;
        QJsonObject *mainObj = new QJsonObject();
        mainObj->insert("id", (int)es->getId());
        mainObj->insert("name", es->getName());
        mainObj->insert("type", "EventSensor");
        QJsonArray vals;
        for(auto val:es->getData()){
            vals.append(val);
        }
        mainObj->insert("values",vals);
        sensorObj=mainObj;
    }
    void JsonVisitor::visitQuantitySensor(QuantitySensor *qs)
    {
        if(sensorObj!=nullptr) delete sensorObj;
        QJsonObject *mainObj = new QJsonObject();
        mainObj->insert("id", (int)qs->getId());
        mainObj->insert("name", qs->getName());
        mainObj->insert("type", "QuantitySensor");
        mainObj->insert("value", (int)qs->getVal());
        sensorObj=mainObj;

    }

    void JsonVisitor::visitXYSensor(XYSensor *xys)
    {
        if(sensorObj!=nullptr) delete sensorObj;
        QJsonObject *mainObj = new QJsonObject();
        mainObj->insert("id", (int)xys->getId());
        mainObj->insert("name", xys->getName());
        mainObj->insert("type", "XYSensor");
        QJsonArray valsX;
        for(auto val:xys->getX()){
            valsX.append(val);
        }
        mainObj->insert("x", valsX);
        QJsonArray valsY;
        for(auto val:xys->getY()){
            valsY.append(val);
        }
        mainObj->insert("y", valsY);
        sensorObj=mainObj;
    }
}