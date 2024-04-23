#include "view/SensorCardWidget.h"
#include <QFrame>
namespace view{
    SensorCardWidget::SensorCardWidget(AbstractSensor* sens, QWidget* parent): QWidget(parent), id(sens->getId()){
        layout=new QHBoxLayout(this);
        setLayout(layout);
        QLabel* idLabel=new QLabel("ID:"+QString::number(sens->getId()));
        name=new QLabel("Name: "+sens->getName());
        layout->addWidget(idLabel);
        layout->addWidget(name);
        setStyleSheet("background-color: #e7e7e7;");
        setFixedHeight(80);
    }
    const quint32& SensorCardWidget::getId() const{
        return id;
    }
}