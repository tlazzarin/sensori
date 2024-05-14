#ifndef VIEW_SENSORVIEWER_SENSORCONTROLWIDGET_H
#define VIEW_SENSORVIEWER_SENSORCONTROLWIDGET_H
// Qt
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
//Librerie
#include "lib/QtAwesome/QtAwesome.h"
using namespace fa;
namespace view{
    namespace sensorViewer{
        class SensorControlWidget : public QWidget{
            Q_OBJECT
            private:
                //Qt/View
                QHBoxLayout* layout;
                QPushButton* simulateButton;
                QPushButton* renameButton;
                QPushButton* deleteButton;
                //Lib/Model
                QtAwesome* awesome;
            public:
                explicit SensorControlWidget(QtAwesome* qta,QWidget* parent=0);
            signals:
                void simulateButtonPressed();
                void renameButtonPressed();
                void deleteButtonPressed();
        };
    }
}
#endif