#include <iostream>
#include "view.h"
#include "game.h"
#include "controllerTui.h"

using namespace abalone;

int main()
{
    View view;
    Game game;
    ControllerTui ctr{view, &game};
    ctr.startGame();
    return 0;
}
