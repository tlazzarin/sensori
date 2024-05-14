#include "SensorRenameWidget.h"
namespace view::sensorViewer{
    SensorRenameWidget::SensorRenameWidget(QtAwesome* qta, QWidget* parent):QWidget(parent), awesome(qta){
        setFixedSize(300,110);
        mainLayout = new QVBoxLayout();
        setLayout(mainLayout);
        //Titolo
        text=new QLabel("Rename the sensor",this);
        text->setAlignment(Qt::AlignCenter);
        mainLayout->addWidget(text);
        //TextBox
        input = new QLineEdit(this);
        input->setMaxLength(30);
        mainLayout->addWidget(input);
        //Buttons layout
        buttonsLayout=new QHBoxLayout();
        mainLayout->addLayout(buttonsLayout);
        //Confirm button
        confirm= new QPushButton(this);
        confirm->setText("Confirm");
        confirm->setIcon(awesome->icon("fa-solid fa-check"));
        buttonsLayout->addWidget(confirm);
        //Cancel button
        cancel = new QPushButton(this);
        cancel->setText("Cancel");
        cancel->setIcon(awesome->icon("fa-solid fa-xmark"));
        buttonsLayout->addWidget(cancel);
        //Error
        error=new QMessageBox(this);
        error->setWindowTitle("Warning");
        error->setIcon(QMessageBox::Warning);
        error->setText("You have to input a string");
        connect(cancel, &QPushButton::clicked, this, &SensorRenameWidget::hide);
        connect(confirm, &QPushButton::clicked, this, &SensorRenameWidget::checkString);
        hide();
    }

    QString SensorRenameWidget::getText() const{
        return input->text();
    }

    void SensorRenameWidget::renameSensor(){
        if(isHidden()){
            input->setText("");
            show();
        }
    }

    void SensorRenameWidget::checkString(){
        if(input->text().length()>0){
            emit newSensorNameReady();
            hide();
        }else{
            error->exec();
        }
    }

}