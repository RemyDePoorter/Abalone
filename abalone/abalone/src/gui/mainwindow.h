#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "appboard.h"
#include "appinfo.h"

namespace abalone {

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private:
    AppBoard *appBoard;
    AppInfo *appInfo;
    controllerGui * _gui;
    Game _game;


};

}
#endif // MAINWINDOW_H
