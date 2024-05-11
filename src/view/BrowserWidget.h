#ifndef VIEW_BROWSERWIDGET_H
#define VIEW_BROWSERWIDGET_H
//Qt
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QScrollArea>
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
            QScrollArea* scrollArea;
            //Lib/model
            QtAwesome* awesome;
            DB* repo;
            //View
            QLineEdit* searchBox;
            SensorsListWidget* sensorsList;
        public:
            explicit BrowserWidget(QtAwesome* qta, DB* mainRepo, QWidget* parent=0);
            const unsigned int getSelectedSensorId() const;
            void setSelectedSensorId(const unsigned int selected); //Quando aggiungo un sensore nuovo lo seleziono
        signals:
            void sensorSelectedChangedToMain(); //Comunica al viewer quale sensore visualizzare
        public slots:
            void refreshList(); //Da chiamare ogni volta che c'è un cambio al DB (import da json, aggiunta, rimozione, modifica) o cambia la ricerca
            void sensorSelectedChangedFromList();
    };
}
#endif