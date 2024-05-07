#include "view/sensorViewer/SensorInspectorWidget.h"
namespace view{
    namespace sensorViewer{
        SensorInspectorWidget::SensorInspectorWidget(QtAwesome* qta, DB* database, QWidget* parent) : QWidget(parent), repo(database), awesome(qta){
            layout=new QVBoxLayout(this);
            layout->setAlignment(Qt::AlignTop);
            //TODO: aggiungere sensor card
            control=new SensorControlWidget(awesome, this);
            layout->addWidget(control);
        }
    }
}