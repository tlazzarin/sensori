#include "view/sensorViewer/SensorInspectorWidget.h"
namespace view{
    namespace sensorViewer{
        SensorInspectorWidget::SensorInspectorWidget(QtAwesome* qta, QWidget* parent) : QWidget(parent), awesome(qta){
            layout=new QVBoxLayout(this);
            layout->setAlignment(Qt::AlignTop);
            //TODO: aggiungere sensor card
            control=new SensorControlWidget(awesome, this);
            layout->addWidget(control);
            //! CONNECT
            connect(control, &SensorControlWidget::simulateButtonPressed, this, &SensorInspectorWidget::simulateSensor);
        }

        void SensorInspectorWidget::simulateSensor(){
            selectedSensor->simulate();
            generateGraph();
        }

        void SensorInspectorWidget::generateGraph(){
            layout->removeWidget(graph);
            selectedSensor->accept(visitor);
            graph=visitor.getWidget();
            graph->setParent(this);
            layout->addWidget(graph);
        }

        void SensorInspectorWidget::setSensor(AbstractSensor* as){
            selectedSensor=as;
            //generateGraph();
        }
    }
}