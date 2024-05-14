#ifndef VIEW_SENSORVIEWER_SENSORRENAMEWIDGET_H
#define VIEW_SENSORVIEWER_SENSORRENAMEWIDGET_H
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QLabel>
#include "lib/QtAwesome/QtAwesome.h"
using namespace fa;
namespace view::sensorViewer{
    class SensorRenameWidget : public QWidget{
        Q_OBJECT
        private:
            //Qt
            QVBoxLayout* mainLayout;
            QHBoxLayout* buttonsLayout;
            QLineEdit* input;
            QPushButton* confirm;
            QPushButton* cancel;
            QMessageBox* error;
            QLabel* text;
            //Lib/Model
            QtAwesome* awesome;
        public:
            SensorRenameWidget(QtAwesome* qta,QWidget* parent=nullptr);
            QString getText() const;
        signals:
            void newSensorNameReady();
        public slots:
        void renameSensor(); // svuota i campi e mostra la finestra se non è già visibile (altrimenti non fa nulla)
        private slots:
        void checkString(); // controlla che i dati inseriti siano validi (stringa>0)
    };
}
#endif