#include <QApplication>
#include <QDebug>
#include "lib/QtAwesome/QtAwesome.h"
#include "model/sensor/XYSensor.h"
#include "model/database/DB.h"
using namespace model::sensor;
int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    fa::QtAwesome* awesome = new fa::QtAwesome();
    awesome->initFontAwesome();
    
    return app.exec();
}