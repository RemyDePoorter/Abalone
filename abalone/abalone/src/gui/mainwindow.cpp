#include "mainwindow.h"
#include <QHBoxLayout>
#include "controllergui.h"

using namespace abalone;

MainWindow::MainWindow()
{
    QHBoxLayout *root = new QHBoxLayout();

    ////Plateau
    appBoard = new AppBoard(&_game);
    root->addLayout(appBoard);
    appBoard->displayBoard();

    ///ControllerGui
    _gui = new controllerGui(&_game,appBoard);

    ////Info
    appInfo = new AppInfo(&_game,*_gui);
    root->addLayout(appInfo);


    setLayout(root);

    resize(1200, 800);


}

MainWindow::~MainWindow()
{

}

