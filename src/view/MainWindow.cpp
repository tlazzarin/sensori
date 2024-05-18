#include "MainWindow.h"
#include <QAction>
#include <QMenu>
#include <QMenuBar>
namespace view
{
    MainWindow::MainWindow(QtAwesome *qta, DB *mainRepo, QWidget *parent) : QMainWindow(parent), awesome(qta), repo(mainRepo)
    {
        setWindowIcon(awesome->icon("fa-solid fa-chart-area"));
        wizard = new NewSensorWizard(awesome);
        setMinimumSize(1280, 800);
        //* Inizializzazione menù a tendina
        QAction *newSensor = new QAction(awesome->icon("fa-solid fa-plus"), "(N) Add New Sensor");
        QAction *importSensors = new QAction(awesome->icon("fa-solid fa-file-arrow-down"), "(I) Import Sensors");
        QAction *exportSensors = new QAction(awesome->icon("fa-solid fa-file-arrow-up"), "(E) Export Sensors");
        QMenu *menu = menuBar()->addMenu("File");
        menu->addAction(newSensor);
        menu->addSeparator();
        menu->addAction(importSensors);
        menu->addAction(exportSensors);
        //* Inizializzazione MainWidget
        splitter = new QSplitter();
        splitter->setChildrenCollapsible(false);
        setCentralWidget(splitter);
        browser = new BrowserWidget(awesome, repo, this);
        browser->setMinimumWidth(300);
        splitter->addWidget(browser);
        inspector = new SensorInspectorWidget(awesome, this);
        splitter->addWidget(inspector);
        //*Shortcuts
        QShortcut *newSensorShortcut = new QShortcut(QKeySequence(tr("n")),this);
        QShortcut *importShortcut = new QShortcut(QKeySequence(tr("i")),this);
        QShortcut *exportShortcut = new QShortcut(QKeySequence(tr("e")),this);
        //! CONNECTS
        connect(newSensor, &QAction::triggered, wizard, &NewSensorWizard::createNewSensor);
        connect(wizard, &NewSensorWizard::newSensorDataReady, this, &MainWindow::createNewSensor);
        connect(browser, &BrowserWidget::sensorSelectedChangedToMain, this, &MainWindow::sensorSelectedChanged);
        connect(inspector, &SensorInspectorWidget::deleteButtonPressed, this, &MainWindow::selectedSensorDeleted);
        connect(inspector, &SensorInspectorWidget::renameConfirmed, this, &MainWindow::sensorRenamedFromInspector);
        connect(exportSensors, &QAction::triggered, this, &MainWindow::exportButtonClicked);
        connect(importSensors, &QAction::triggered, this, &MainWindow::importButtonClicked);
        connect(newSensorShortcut, &QShortcut::activated, wizard, &NewSensorWizard::createNewSensor);
        connect(importShortcut, &QShortcut::activated, this, &MainWindow::importButtonClicked);
        connect(exportShortcut, &QShortcut::activated, this, &MainWindow::exportButtonClicked);
    }

    void MainWindow::createNewSensor()
    {
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
        browser->setSelectedSensorId(repo->getLastSensorId());
        browser->refreshList();
        inspector->setSensor(repo->get(repo->getLastSensorId()));
        inspector->generateGraph();
    }

    void MainWindow::sensorSelectedChanged()
    {
        inspector->setSensor(repo->get(browser->getSelectedSensorId()));
    }

    void MainWindow::selectedSensorDeleted()
    {
        repo->remove(browser->getSelectedSensorId());
        inspector->setSensor(repo->get(repo->getFirstSensorId()));
        browser->setSelectedSensorId(repo->getFirstSensorId());
    }

    void MainWindow::sensorRenamedFromInspector()
    {
        if (repo->get(browser->getSelectedSensorId()) != nullptr)
            repo->get(browser->getSelectedSensorId())->setName(inspector->getSensorNewName());
        browser->refreshList();
        inspector->setSensor(repo->get(browser->getSelectedSensorId()));
    }

    void MainWindow::exportButtonClicked()
    {
        if (repo->getFirstSensorId() != 0)
        {
            QString path = QFileDialog::getSaveFileName(this, tr("Export sensors"), "./sensors.json", tr("Json files (*.json)"));
            if(path==nullptr) return;
            repo->saveToFile(path);
        }
        else
            QMessageBox::warning(this, "No sensors", "You must have at least one sensor.");
    }

    void MainWindow::importButtonClicked()
    {
        // Se ho almeno un sensore chiedo all'utente se è sicuro che li vuole sovrascrivere
        if (repo->getFirstSensorId() != 0)
        {
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Sensor replace", "Do you want to replace the current sensors?", QMessageBox::Yes | QMessageBox::No);
            if (reply == QMessageBox::No)
                return;
        }
        QString path = QFileDialog::getOpenFileName(this, tr("Import sensors"), "./", tr("Json files (*.json)"));
        if(path==nullptr) return;
        if (repo->loadFromFile(path))
        {
            inspector->setSensor(repo->get(repo->getFirstSensorId()));
            browser->setSelectedSensorId(repo->getFirstSensorId());
        }
        else
            QMessageBox::warning(this, "Parsing error", "There was an error in your document parsing");
    }

    void MainWindow::closeEvent(QCloseEvent *event)
    {
        event->ignore();
        if (repo->getFirstSensorId() != 0 &&
            QMessageBox::No == QMessageBox::question(this, "Close", "Are you sure that you want to close the program?", QMessageBox::Yes | QMessageBox::No))
            return;
        QMainWindow::closeEvent(event);
    }
}