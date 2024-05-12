#include "view/SensorsListWidget.h"
namespace view{
    SensorsListWidget::SensorsListWidget(DB* db,QWidget* parent): QWidget(parent), repo(db){
        layout = new QVBoxLayout(this);
        setLayout(layout);
        layout->addStretch();
    }

    void SensorsListWidget::generateView(const QString& query){
        this->query=query;
        qDeleteAll(findChildren<SensorCardWidget*>());
        cardsList.clear();
        QList<AbstractSensor*> queryResult=repo->search(query);
        SensorCardWidget* temp=nullptr;
        for(auto sensor : queryResult){
            temp=new SensorCardWidget(sensor,sensor->getId()==selectedSensorId?true:false, this);
            cardsList.append(temp);
            layout->insertWidget(layout->count()-1,temp);
            connect(temp, &SensorCardWidget::clicked, this, &SensorsListWidget::clickEvent);
        }
    }

    void SensorsListWidget::clickEvent(){
        SensorCardWidget* obj=qobject_cast<SensorCardWidget*>(sender());
        selectedSensorId=obj->getId();
        generateView(query);
        emit newSensorSelectedToBrowser();
    }

    void SensorsListWidget::setSelectedSensorId(unsigned int selected){
        selectedSensorId=selected;
        generateView(query);
    }

    unsigned int SensorsListWidget::getSelectedSensorId() const{
        return selectedSensorId;
    }
}