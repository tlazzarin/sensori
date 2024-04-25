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
            quint32 id;
            QLabel* name;
        protected:
            void mousePressEvent(QMouseEvent* event);
        public:
            explicit SensorCardWidget(AbstractSensor* sens, bool selected, QWidget* parent=0);
            const quint32& getId() const;
        signals:
            void clicked();
    };
}
#endif