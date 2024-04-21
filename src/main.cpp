#include <QApplication>
#include <QDebug>
#include "lib/QtAwesome/QtAwesome.h"
#include "model/database/DB.h"
#include "view/MainWindow.h"
#include "model/sensor/QuantitySensor.h"//TODO: DA TOGLIERE
#include "model/sensor/XYSensor.h" //TODO: DA TOGLIERE

using namespace model::sensor;
using namespace view;
int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    //QtAwesome: libreria che permette di utilizzare le icone di FontAwesome su Qt https://github.com/gamecreature/QtAwesome
    //Bisogna creare un'unica istanza per applicazione
    fa::QtAwesome* awesome = new fa::QtAwesome();
    awesome->initFontAwesome();
    //Inizializzo la repository di tutti i sensori, dato che è unica lo faccio nel main.
    model::database::DB *repo=new model::database::DB();
    MainWindow w(awesome, repo);
    w.show();
    return app.exec();
}