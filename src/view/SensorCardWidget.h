#ifndef VIEW_SENSORCARDWIDGET_H
#define VIEW_SENSORCARDWIDGET_H
//Qt
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
//Model
#include "model/sensor/AbstractSensor.h"
using namespace model::sensor;
namespace view{
    class SensorCardWidget : public QWidget{
        Q_OBJECT
        private:
            QHBoxLayout* layout;
            AbstractSensor* s;
            QLabel* id;
            QLabel* name;
        public:
            explicit SensorCardWidget(AbstractSensor* sens, QWidget* parent=0);
    };
}
#endif