#include "view/sensorViewer/SensorControlWidget.h"
namespace view{
    namespace sensorViewer{
        SensorControlWidget::SensorControlWidget(QtAwesome* qta, QWidget* parent) : QWidget(parent), awesome(qta){
            layout=new QHBoxLayout(this);
            simulateButton=new QPushButton(awesome->icon("fa-solid fa-play"),"Simulate",this);
            simulateButton->setMinimumHeight(50);
            layout->addWidget(simulateButton);
            editButton=new QPushButton(awesome->icon("fa-solid fa-pen-to-square"),"Edit",this);
            editButton->setMinimumHeight(50);
            layout->addWidget(editButton);
            deleteButton=new QPushButton(awesome->icon("fa-solid fa-trash"),"Delete",this);
            deleteButton->setMinimumHeight(50);
            layout->addWidget(deleteButton);
            //! CONNECT
            connect(simulateButton, &QPushButton::clicked, this, &SensorControlWidget::simulateButtonPressed);
            connect(editButton, &QPushButton::clicked, this, &SensorControlWidget::editButtonPressed);
            connect(deleteButton, &QPushButton::clicked, this, &SensorControlWidget::deleteButtonPressed);
        }
    }
}