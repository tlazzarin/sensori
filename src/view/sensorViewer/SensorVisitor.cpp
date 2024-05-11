#include "SensorVisitor.h"
namespace view::sensorViewer
{

    QWidget *SensorVisitor::getWidget()
    {
        return widget;
    }

    void SensorVisitor::visitQuantitySensor(QuantitySensor *qs)
    {
        QProgressBar *bar = new QProgressBar();
        bar->setRange(0, 100);
        bar->setValue(qs->getVal());
        qDebug() << "visitQuantitySensor";
        widget = bar;
    }

    void SensorVisitor::visitEventSensor(EventSensor *es)
    {
        qDebug() << "visitEventSensor";
    }

    void SensorVisitor::visitXYSensor(XYSensor *xys)
    {
        qDebug() << "visitXYSensor";
    }
}