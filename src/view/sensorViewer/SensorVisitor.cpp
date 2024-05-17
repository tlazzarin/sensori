#include "SensorVisitor.h"
namespace view::sensorViewer
{

    QWidget *SensorVisitor::getWidget()
    {
        return widget;
    }

    void SensorVisitor::visitQuantitySensor(QuantitySensor *qs)
    {
        QWidget *w = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout();
        layout->setAlignment(Qt::AlignTop | Qt::AlignVCenter);
        w->setLayout(layout);
        QLabel *title = new QLabel(w);
        title->setText("["+QString::fromStdString(std::to_string(qs->getId()))+"] "+qs->getName()+" | Quantity sensor, it shows the current value of a sensor.");
        layout->addWidget(title);
        QProgressBar *bar = new QProgressBar();
        bar->setRange(0, 1000);
        bar->setFormat("%v/%m");
        bar->setValue(qs->getVal());
        bar->setMinimumHeight(80);
        bar->setStyleSheet("QProgressBar { border: 2px solid grey; border-radius: 0px; text-align: center; } QProgressBar::chunk {background-color: #36dddd; width: 1px;}");
        layout->addWidget(bar);
        widget = w;
    }

    void SensorVisitor::visitEventSensor(EventSensor *es)
    {
        QChart *chart = new QChart();
        chart->setTitle("["+QString::fromStdString(std::to_string(es->getId()))+"] "+es->getName()+" | Event sensor, it shows how many times an event has taken place each day.");
        // Definizione asse x
        QStringList days{"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
        auto axisX = new QBarCategoryAxis();
        axisX->append(days);
        chart->addAxis(axisX, Qt::AlignBottom);
        // Definizione asse y
        auto axisY = new QValueAxis();
        axisY->setRange(0, 15);
        chart->addAxis(axisY, Qt::AlignLeft);
        // Definizione dati
        auto barSet = new QBarSet("Events");
        for (auto item : es->getData()) *barSet << item;
        auto series = new QBarSeries();
        series->append(barSet);
        chart->addSeries(series);
        series->attachAxis(axisY);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
        widget = new QChartView(chart);
    }

    void SensorVisitor::visitXYSensor(XYSensor *xys)
    {
        QChart *chart=new QChart();
        chart->setTitle("["+QString::fromStdString(std::to_string(xys->getId()))+"] "+xys->getName()+" | XY Sensor with 10 samples (x in [0,10], y in [0,100]).");
        chart->legend()->hide();
        //Asse X
        auto axisX = new QValueAxis();
        axisX->setRange(0,10);
        axisX->setTickCount(21);
        chart->addAxis(axisX,Qt::AlignBottom);
        //Asse Y
        auto axisY = new QValueAxis();
        axisY->setTickCount(21);
        axisY->setRange(0,100);
        chart->addAxis(axisY, Qt::AlignLeft);
        //Definizione dati
        auto series = new QLineSeries;
        auto xVals = xys->getX();
        auto yVals = xys->getY();
        for(int i=0; i<xVals.size(); ++i) series->append(xVals[i], yVals[i]);
        chart->addSeries(series);
        series->attachAxis(axisX);
        series->attachAxis(axisY);
        widget = new QChartView(chart);
    }
}