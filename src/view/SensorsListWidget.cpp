#include "view/SensorsListWidget.h"
namespace view{
    SensorsListWidget::SensorsListWidget(DB* db,QWidget* parent): QWidget(parent), repo(db){
        layout = new QVBoxLayout(this);
        setLayout(layout);
        layout->addStretch();
    }

    void SensorsListWidget::generateView(const QString& query){
        qDeleteAll(findChildren<SensorCardWidget*>());
        cardsList.clear();
        QList<AbstractSensor*> queryResult=repo->search(query);
        SensorCardWidget* temp=nullptr;
        for(auto sensor : queryResult){
            temp=new SensorCardWidget(sensor,this);
            cardsList.append(temp);
            layout->insertWidget(layout->count()-1,temp);
        }
    }
}