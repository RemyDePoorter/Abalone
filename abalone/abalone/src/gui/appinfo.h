#ifndef APPINFO_H
#define APPINFO_H

#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include "game.h"
#include "controllergui.h"

namespace abalone {

class AppInfo : public QFormLayout
{

public:
    AppInfo(Game * game, controllerGui & gui);
    ~AppInfo();
    void setupSignals();
    void update();

private:
    Game *_game;
    controllerGui _gui;
    void initInterface();
    int nbBlack;
    QLabel *nbBallBlack;

    int nbWhite;
    QLabel *nbBallWhite;

    PlayerColor current;
    QLabel *labelCurrent;

    QPushButton *button;

    QLabel *msgError;

    QLabel *msgWin;

private slots:
    void confirmedMove();
};

}
#endif // APPINFO_H
