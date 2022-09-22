#ifndef APPBOARD_H
#define APPBOARD_H

#include <QGridLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "game.h"
#include "hexacell.h"

namespace abalone {

class AppBoard : public QGridLayout
{

public:
    AppBoard(Game * game);
    ~AppBoard();
    void update();
    void displayBoard();
    std::string getMove();

private:
    HexaCell *plateau[9][9];
    Game *_game;
    QGraphicsScene * _scene;
    QGraphicsView * _view;


};

}
#endif // APPBOARD_H
