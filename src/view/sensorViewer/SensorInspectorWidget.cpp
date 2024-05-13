#include "view/sensorViewer/SensorInspectorWidget.h"
namespace view{
    namespace sensorViewer{
        SensorInspectorWidget::SensorInspectorWidget(QtAwesome* qta, QWidget* parent) : QWidget(parent), graph(nullptr), awesome(qta), selectedSensor(nullptr){
            setMinimumWidth(900);
            layout=new QVBoxLayout(this);
            layout->setAlignment(Qt::AlignTop);
            //Control buttons setup
            control=new SensorControlWidget(awesome, this);
            layout->addWidget(control);
            control->setVisible(false);
            //Welcome panel setup
            welcomeText = new QLabel(this);
            welcomeText->setAlignment(Qt::AlignLeft);
            welcomeText->setText("<h1>Welcome!</h1>\nTo get started go to File->Add New Sensor or import a sensor setup!");
            layout->addWidget(welcomeText);
            showWelcomeText(true);
            //! CONNECT
            connect(control, &SensorControlWidget::simulateButtonPressed, this, &SensorInspectorWidget::simulateSensor);
            connect(control, &SensorControlWidget::deleteButtonPressed, this, &SensorInspectorWidget::deleteButtonPressed);
        }

        void SensorInspectorWidget::simulateSensor(){
            selectedSensor->simulate();
            generateGraph();
        }

        void SensorInspectorWidget::generateGraph(){
            if(graph!=nullptr){
                layout->removeWidget(graph);
                delete graph;
            }
            control->setVisible(true);
            selectedSensor->accept(visitor);
            graph=visitor.getWidget();
            graph->setParent(this);
            layout->addWidget(graph);
        }

        void SensorInspectorWidget::setSensor(AbstractSensor* as){
            if(as!=nullptr){
                selectedSensor=as;
                generateGraph();
                showWelcomeText(false);
            }else{
                control->setVisible(false);
                graph->setVisible(false);
                showWelcomeText(true);
            }
        }

        void SensorInspectorWidget::showWelcomeText(bool status){
            welcomeText->setVisible(status);
        }
    }
}