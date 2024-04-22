#include "view/SensorCardWidget.h"
namespace view{
    SensorCardWidget::SensorCardWidget(AbstractSensor* sens, QWidget* parent): QWidget(parent), s(sens){
        layout=new QHBoxLayout(this);
        setLayout(layout);
        id=new QLabel(QString::number(s->getId()));
        name=new QLabel(s->getName());
    }
}