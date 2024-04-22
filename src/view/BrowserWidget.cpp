#include "BrowserWidget.h"

namespace view{
    BrowserWidget::BrowserWidget(QtAwesome* qta, DB* mainRepo, QWidget* parent): QWidget(parent),awesome(qta), repo(mainRepo){
        layout=new QVBoxLayout(this);
        setLayout(layout);
        searchBox=new QLineEdit(this);
        searchBox->setPlaceholderText("Search sensor");
        layout->addWidget(searchBox);
        sensorsList=new SensorsListWidget(repo, this);
        layout->addWidget(sensorsList);
        setStyleSheet("background-color: blue;");
    }
}