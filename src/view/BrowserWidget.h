#ifndef VIEW_BROWSERWIDGET_H
#define VIEW_BROWSERWIDGET_H
//Qt
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
//Librerie
#include "lib/QtAwesome/QtAwesome.h"
//Model
#include "model/database/DB.h"
//View
#include "view/SensorsListWidget.h"
using namespace model::database;
using namespace fa;
namespace view{
    class BrowserWidget : public QWidget{
        Q_OBJECT
        private:
            //Layout
            QVBoxLayout* layout;
            //Lib/model
            QtAwesome* awesome;
            DB* repo;
            //View
            QLineEdit* searchBox;
            SensorsListWidget* sensorsList;
        public:
            explicit BrowserWidget(QtAwesome* qta, DB* mainRepo, QWidget* parent=0);
            const quint32& getSelectedSensorId() const;
        signals:
            void sensorSelectedChanged(); //Comunica al viewer quale sensore visualizzare
        public slots:
            //void refreshDb(); //Da chiamare ogni volta che c'è un cambio al DB (import da json, aggiunta, rimozione, modifica)
    };
}
#endif