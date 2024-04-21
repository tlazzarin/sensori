#include "NewSensorWizard.h"
namespace view
{
    NewSensorWizard::NewSensorWizard(QtAwesome *fa) : awesome(fa)
    {
        //Se chiudo la main window mentre questa finestra è aperta, viene chiusa anche questa: https://stackoverflow.com/questions/16468584/qwidget-doesnt-close-when-main-window-is-closed
        setAttribute(Qt::WA_QuitOnClose, false);
        setWindowTitle("Create new sensor");
        setFixedSize(300, 170);
        setWindowIcon(awesome->icon(fa::fa_solid, fa::fa_arrow_up_right_from_square));
        layout = new QVBoxLayout(this);
        setLayout(layout);
        QLabel *title = new QLabel("Create new sensor", this);
        title->setAlignment(Qt::AlignCenter);
        layout->addWidget(title);
        newSensorName = new QLineEdit(this);
        newSensorName->setPlaceholderText("Sensor name");
        layout->addWidget(newSensorName);
        sensorTypesButtonsList = QList<QRadioButton *>();
        sensorTypesButtonsList.append(new QRadioButton("Quantity sensor (0-100 gauge)", this));
        sensorTypesButtonsList.append(new QRadioButton("Event sensor (bar chart)", this));
        sensorTypesButtonsList.append(new QRadioButton("XY sensor (line chart)", this));
        sensorTypesButtonsList[0]->setIcon(awesome->icon(fa::fa_solid, fa::fa_gauge));
        sensorTypesButtonsList[1]->setIcon(awesome->icon(fa::fa_solid, fa::fa_chart_simple));
        sensorTypesButtonsList[2]->setIcon(awesome->icon(fa::fa_solid, fa::fa_chart_line));
        radioButtonsLayout = new QVBoxLayout(this);
        sensorTypeGroup = new QButtonGroup(this);
        for (int i = 0; i < sensorTypesButtonsList.size(); i++)
        {
            sensorTypeGroup->addButton(sensorTypesButtonsList[i]);
            radioButtonsLayout->addWidget(sensorTypesButtonsList[i]);
        }
        layout->addLayout(radioButtonsLayout);
        buttonsLayout = new QHBoxLayout(this);
        confirmButton = new QPushButton("Create", this);
        confirmButton->setIcon(awesome->icon(fa::fa_solid, fa::fa_check));
        buttonsLayout->addWidget(confirmButton);
        cancelButton = new QPushButton("Cancel", this);
        cancelButton->setIcon(awesome->icon(fa::fa_solid, fa::fa_times));
        buttonsLayout->addWidget(cancelButton);
        layout->addLayout(buttonsLayout);
        sensorTypesButtonsList[0]->setChecked(true);
        // error message
        error = new QMessageBox(this);
        error->setWindowTitle("Warning: no name or type selected");
        error->setIcon(QMessageBox::Warning);
        error->setText("Remember to set a name and choose a type for the new sensor!");
        // connect
        connect(cancelButton, &QPushButton::clicked, this, &NewSensorWizard::hide);
        connect(confirmButton, &QPushButton::clicked, this, &NewSensorWizard::checkSensorData);
    }

        void NewSensorWizard::clean()
    {
        newSensorName->setText("");
        sensorTypeGroup->setExclusive(false); // fix
        for (int i = 0; i < sensorTypesButtonsList.size(); i++)
        {
            sensorTypeGroup->setId(sensorTypesButtonsList[i], i);
            sensorTypesButtonsList[i]->setChecked(false);
        }
        sensorTypeGroup->setExclusive(true);
    }

    void NewSensorWizard::createNewSensor()
    {
        if (isHidden())
        {
            clean();
            show();
        }
    }

    QString NewSensorWizard::getNewSensorName()
    {
        return newSensorName->text();
    }

    int NewSensorWizard::getNewSensorType()
    {
        return sensorTypeGroup->checkedId();
    }

    void NewSensorWizard::checkSensorData()
    {
        if (newSensorName->text().length() > 0 && sensorTypeGroup->checkedId() != -1)
        {
            emit newSensorDataReady();
            hide();
        }
        else
            error->exec();
    }
}