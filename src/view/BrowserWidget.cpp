#include "BrowserWidget.h"

namespace view{
    BrowserWidget::BrowserWidget(QtAwesome* qta, DB* mainRepo, QWidget* parent): QWidget(parent),awesome(qta), repo(mainRepo){
        layout=new QVBoxLayout(this);
        setLayout(layout);
        //SearchBox
        searchBox=new QLineEdit(this);
        searchBox->setPlaceholderText("Search sensor");
        layout->addWidget(searchBox);
        //Sensors List
        scrollArea=new QScrollArea(this);
        sensorsList=new SensorsListWidget(repo, scrollArea);
        scrollArea->setWidget(sensorsList);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignTop);
        layout->addWidget(scrollArea);
        //setStyleSheet("background-color: blue;");
        //!CONNECT
        connect(searchBox, &QLineEdit::textChanged, this, &BrowserWidget::refreshList);
        connect(sensorsList, &SensorsListWidget::newSensorSelectedToBrowser, this, &BrowserWidget::sensorSelectedChangedFromList);
    }
    void BrowserWidget::refreshList(){
        sensorsList->generateView(searchBox->text());
    }

    const quint32& BrowserWidget::getSelectedSensorId() const{
        return sensorsList->getSelectedSensorId();
    }
    void BrowserWidget::setSelectedSensorId(const quint32& selected){
        sensorsList->setSelectedSensorId(selected);
    }

    void BrowserWidget::sensorSelectedChangedFromList(){
        emit sensorSelectedChangedToMain();
    }
}