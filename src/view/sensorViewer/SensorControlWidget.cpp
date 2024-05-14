#include "view/sensorViewer/SensorControlWidget.h"
namespace view{
    namespace sensorViewer{
        SensorControlWidget::SensorControlWidget(QtAwesome* qta, QWidget* parent) : QWidget(parent), awesome(qta){
            layout=new QHBoxLayout(this);
            simulateButton=new QPushButton(awesome->icon("fa-solid fa-play"),"Simulate",this);
            simulateButton->setMinimumHeight(50);
            layout->addWidget(simulateButton);
            renameButton=new QPushButton(awesome->icon("fa-solid fa-pen-to-square"),"Rename",this);
            renameButton->setMinimumHeight(50);
            layout->addWidget(renameButton);
            deleteButton=new QPushButton(awesome->icon("fa-solid fa-trash"),"Delete",this);
            deleteButton->setMinimumHeight(50);
            layout->addWidget(deleteButton);
            //! CONNECT
            connect(simulateButton, &QPushButton::clicked, this, &SensorControlWidget::simulateButtonPressed);
            connect(renameButton, &QPushButton::clicked, this, &SensorControlWidget::renameButtonPressed);
            connect(deleteButton, &QPushButton::clicked, this, &SensorControlWidget::deleteButtonPressed);
        }
    }
}