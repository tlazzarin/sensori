#include "SensorVisitor.h"
#include <QLabel>
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
        widget = bar;
    }

    void SensorVisitor::visitEventSensor(EventSensor *es)
    {
        QChart *chart = new QChart();
        chart->setTitle("Event sensor");
        //Definizione asse x
        QStringList days {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
        auto axisX = new QBarCategoryAxis();
        axisX->append(days);
        chart->addAxis(axisX, Qt::AlignBottom);
        //Definizione asse y
        auto axisY = new QValueAxis();
        axisY->setRange(0,15);
        chart->addAxis(axisY, Qt::AlignLeft);
        //Definizione dati
        auto barSet=new QBarSet("Events");
        for(auto item : es->getData()){
            *barSet<<item;
        }
        auto series = new QBarSeries();
        series->append(barSet);
        series->attachAxis(axisY);
        chart->addSeries(series);
        //chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
        widget=new QChartView(chart);
        qDebug() << "visitEventSensor";
    }

    void SensorVisitor::visitXYSensor(XYSensor *xys)
    {
        qDebug() << "visitXYSensor";
    }
}