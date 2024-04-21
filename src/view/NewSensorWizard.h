#ifndef VIEW_NEWSENSORWIZARD_H
#define VIEW_NEWSENSORWIZARD_H
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QButtonGroup>
#include <QRadioButton>
#include <QList>
#include <QPushButton>
#include <QMessageBox>
#include "lib/QtAwesome/QtAwesome.h"
using namespace fa;
namespace view
{
    class NewSensorWizard : public QWidget
    {
        Q_OBJECT
    private:
        QtAwesome *awesome;
        QMessageBox *error;
        QVBoxLayout *layout; //Main layout: Titolo | Nome | Radio Button | Bottoni Crea/Cancella
        QLineEdit *newSensorName;
        QButtonGroup *sensorTypeGroup; //Garantisce l'esclusività del bottone cliccato
        QList<QRadioButton *> sensorTypesButtonsList;
        QPushButton *confirmButton;
        QPushButton *cancelButton;
        QHBoxLayout *buttonsLayout;
        QVBoxLayout *radioButtonsLayout;
        void clean();

    public:
        explicit NewSensorWizard(QtAwesome *fa);
        QString getNewSensorName();
        int getNewSensorType();
    signals:
        void newSensorDataReady(); // avvisa (la mainwindow) che è stato creato un nuovo sensore
    public slots:
        void createNewSensor(); // svuota i campi e mostra la finestra se non è già visibile (altrimenti non fa nulla)
    private slots:
        void checkSensorData(); // controlla che i dati inseriti siano validi (stringa>0, tipo selezionato)
    };
}

#endif