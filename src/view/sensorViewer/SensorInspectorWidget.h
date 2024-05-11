#ifndef VIEW_SENSORVIEWER_SENSORINSPECTORWIDGET_H
#define VIEW_SENSORVIEWER_SENSORINSPECTORWIDGET_H
// Qt
#include <QWidget>
#include <QVBoxLayout>
// View
#include "view/SensorCardWidget.h"
#include "SensorControlWidget.h"
#include "SensorVisitor.h"
// Librerie
#include "lib/QtAwesome/QtAwesome.h"
// Model
#include "model/database/DB.h"
#include "model/sensor/AbstractSensor.h"
using namespace model::database;
using namespace model::sensor;
using namespace fa;
namespace view
{
    namespace sensorViewer
    {
        // Questa classe conterrà tutti gli elementi che si occupano di mostrare i dati del sensore all'utente (titolo, pulsanti di modifica, grafico)
        class SensorInspectorWidget : public QWidget
        {
            Q_OBJECT
        private:
            // Qt
            QVBoxLayout *layout;
            // View
            // SensorCardWidget *card; // Riutilizzo la card che avevo fatto per mostrare nome e id del sensore
            SensorControlWidget *control;
            QWidget *graph;

            // Lib/Model
            QtAwesome *awesome;
            AbstractSensor *selectedSensor; //! Alla creazione dell'inspector sarà null, forse avrebbe più senso prenderlo ogni volta dalla repo
            SensorVisitor visitor;

        public:
            explicit SensorInspectorWidget(QtAwesome *qta, QWidget *parent = 0);
            void setSensor(AbstractSensor *sensor);
        private slots:
            void simulateSensor();

        public slots:
            void generateGraph();
        };
    }
}
#endif