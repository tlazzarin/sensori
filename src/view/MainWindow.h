#ifndef VIEW_MAINWINDOW_H
#define VIEW_MAINWINDOW_H
//Qt
#include <QMainWindow>
#include <QSplitter>
//Librerie
#include "lib/QtAwesome/QtAwesome.h"
//Model
#include "model/database/DB.h"
#include "model/sensor/QuantitySensor.h"
#include "model/sensor/EventSensor.h"
#include "model/sensor/XYSensor.h"
//View
#include "NewSensorWizard.h"
using namespace model::database;
using namespace fa;
namespace view{
    class MainWindow : public QMainWindow{
        Q_OBJECT
        private:
            //Qt layout
            QSplitter* splitter;
            //Lib/model
            QtAwesome* awesome;
            DB* repo;
            //View
            NewSensorWizard* wizard;
        public:
            explicit MainWindow(QtAwesome* qta, DB* mainRepo, QWidget* parent=0);
        public slots:
            void createNewSensor(); //Il wizard userà questo slot per dire che i dati del nuovo sensore sono pronti per essere inseriti nel db.
    };
}

#endif