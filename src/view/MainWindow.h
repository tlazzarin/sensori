#ifndef VIEW_MAINWINDOW_H
#define VIEW_MAINWINDOW_H
//Qt
#include <QMainWindow>
#include <QSplitter>
//Librerie
#include "lib/QtAwesome/QtAwesome.h"
//Model
#include "model/database/DB.h"
using namespace model::database;
using namespace fa;
namespace view{
    class MainWindow : public QMainWindow{
        Q_OBJECT
        private:
            //Qt
            QSplitter* splitter;
            //Lib/model
            QtAwesome* awesome;
            DB* repo;
        public:
            explicit MainWindow(QtAwesome* qta, DB* main_repo);
    };
}

#endif