#include <QApplication>
#include <QDebug>
#include "lib/QtAwesome/QtAwesome.h"
#include "model/sensor/QuantitySensor.h"
#include "model/sensor/XYSensor.h"
#include "model/database/DB.h"
using namespace model::sensor;
int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    //QtAwesome: libreria che permette di utilizzare le icone di FontAwesome su Qt https://github.com/gamecreature/QtAwesome
    //Bisogna creare un'unica istanza per applicazione
    fa::QtAwesome* awesome = new fa::QtAwesome();
    awesome->initFontAwesome();
    //Inizializzo la repository di tutti i sensori, dato che è unica lo faccio nel main.
    model::database::DB *repo=new model::database::DB();
    return app.exec();
}