#ifndef VIEW_SENSORSLISTWIDGET_H
#define VIEW_SENSORSLISTWIDGET_H
//Qt
#include <QWidget>
#include <QVBoxLayout>
//Model
#include "model/database/DB.h"
//view
#include "SensorCardWidget.h"
using namespace model::database;
namespace view{
    class SensorsListWidget : public QWidget{
        Q_OBJECT
        private:
            //Qt
            QVBoxLayout* layout;
            //Model
            DB* repo;
            //View
            QList<SensorCardWidget*> cardList;
        public:
            explicit SensorsListWidget(DB* db,QWidget* parent=0);
            void generateView(const QString& query); //Ogni volta che l'utente cambia un carattere nella ricerca ricreo la view
    };
}
#endif