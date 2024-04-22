#include "view/SensorsListWidget.h"
namespace view{
    SensorsListWidget::SensorsListWidget(DB* db,QWidget* parent): QWidget(parent), repo(db){
        layout = new QVBoxLayout(this);
        setLayout(layout);
        setStyleSheet("background-color:red;");
        setMinimumHeight(400);
    }
}