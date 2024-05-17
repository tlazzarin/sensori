#include "view/SensorCardWidget.h"
#include <QFrame>
namespace view{
        SensorCardWidget::SensorCardWidget(AbstractSensor* sens, bool selected,QWidget* parent): QWidget(parent), id(sens->getId()){
        layout=new QHBoxLayout(this);
        setLayout(layout);
        layout->setAlignment(Qt::AlignLeft);
        QLabel* idLabel=new QLabel("ID: "+QString::number(sens->getId()));
        idLabel->setFixedWidth(80);
        name=new QLabel("Name: "+sens->getName());
        layout->addWidget(idLabel);
        layout->addWidget(name);
        QPalette pal;
        setAutoFillBackground(true);
        if(selected)
            pal.setColor(QPalette::Window, QColor(205,205,205));
        else
            pal.setColor(QPalette::Window, QColor(225,225,225));
        setPalette(pal);
    }
    unsigned int SensorCardWidget::getId() const{
        return id;
    }

    void SensorCardWidget::mouseReleaseEvent(QMouseEvent*){
        emit clicked();
    }
}