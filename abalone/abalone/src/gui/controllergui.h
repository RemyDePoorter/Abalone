#ifndef CONTROLLERGUI_H
#define CONTROLLERGUI_H
#include "game.h"
#include "appboard.h"
#include "controller.h"

namespace abalone {

class controllerGui : public Controller{
public:
    controllerGui(Game * game, AppBoard * appBoard);
    bool makeMove();

private:
    AppBoard * _appBoard;
};

}
#endif // CONTROLLERGUI_H
