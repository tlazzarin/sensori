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
            quint32 selectedSensorId;
            //View
            QList<SensorCardWidget*> cardsList;
            QString query;
        public:
            explicit SensorsListWidget(DB* db,QWidget* parent=0);
            void generateView(const QString& query); //Ogni volta che l'utente cambia un carattere nella ricerca o carica un json ricreo la view
            const quint32& getSelectedSensorId() const;
            void setSelectedSensorId(const quint32& selected);
        private:
            void generateView();
        signals:
            void newSensorSelectedToBrowser(); //Da mandare al BrowserWidget 
        public slots:
            void clickEvent();
    };
}
#endif