#include "view/SensorCardWidget.h"
#include <QFrame>
namespace view{
    SensorCardWidget::SensorCardWidget(AbstractSensor* sens, bool selected,QWidget* parent): QWidget(parent), id(sens->getId()){
        layout=new QHBoxLayout(this);
        setLayout(layout);
        QLabel* idLabel=new QLabel("ID:"+QString::number(sens->getId()));
        name=new QLabel("Name: "+sens->getName());
        layout->addWidget(idLabel);
        layout->addWidget(name);
        if(selected)
            setStyleSheet("background-color: #e7e7e7; color: red;");
        else
            setStyleSheet("background-color: #e7e7e7;");
        setFixedHeight(80);
    }
    const quint32& SensorCardWidget::getId() const{
        return id;
    }

    void SensorCardWidget::mousePressEvent(QMouseEvent* event){
        emit clicked();
    }
}