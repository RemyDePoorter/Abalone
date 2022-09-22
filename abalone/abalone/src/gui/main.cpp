#include <QApplication>
#include "mainwindow.h"

using namespace abalone;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Abalone");
    w.show();
    return a.exec();
}
