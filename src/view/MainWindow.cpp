#include "MainWindow.h"
#include <QAction>
#include <QMenu>
#include <QMenubar>
namespace view{
    MainWindow::MainWindow(QtAwesome* qta, DB* mainRepo, QWidget* parent): QMainWindow(parent), awesome(qta), repo(mainRepo){
        setWindowIcon(awesome->icon("fa-solid fa-chart-area"));
        wizard = new NewSensorWizard(awesome);
        setMinimumSize(900,600);
        //* Inizializzazione menù a tendina
        QAction* newSensor = new QAction(awesome->icon("fa-solid fa-plus"), "Add New Sensor");
        QAction* importSensors = new QAction(awesome->icon("fa-solid fa-file-arrow-down"), "Import Sensors");
        QAction* exportSensors = new QAction(awesome->icon("fa-solid fa-file-arrow-up"), "Export Sensors");
        QAction* close = new QAction(awesome->icon("fa-solid fa-xmark"), "Close");
        QMenu* menu = menuBar()->addMenu("File");
        menu->addAction(newSensor);
        menu->addSeparator();
        menu->addAction(importSensors);
        menu->addAction(exportSensors);
        menu->addSeparator();
        menu->addAction(close);
        //* Inizializzazione MainWidget
        splitter=new QSplitter();
        setCentralWidget(splitter);
        browser=new BrowserWidget(awesome,repo,this);
        browser->setMinimumWidth(300);
        splitter->addWidget(browser);
        //!CONNECTS
        connect(close, &QAction::triggered, this, &MainWindow::close); //chiude l'applicazione
        connect(newSensor, &QAction::triggered, wizard, &NewSensorWizard::createNewSensor);
        connect(wizard, NewSensorWizard::newSensorDataReady, this, &MainWindow::createNewSensor);
    }

    void MainWindow::createNewSensor(){
        switch (wizard->getNewSensorType())
        {
        case 0:
            repo->insert(new QuantitySensor(wizard->getNewSensorName()));
            break;
        case 1:
            repo->insert(new EventSensor(wizard->getNewSensorName()));
            break;
        case 2:
            repo->insert(new XYSensor(wizard->getNewSensorName()));
            break;
        default:
            break;
        }
    }
}