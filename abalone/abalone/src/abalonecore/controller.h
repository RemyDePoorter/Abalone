#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "position.h"
#include "string"
#include "game.h"

namespace abalone {

class Controller
{
protected:
    Game * _game;
    Controller(Game * game) : _game(game){}
public :
    /**
     * @brief checkCommandSyntax
     * Checks the size and syntax of a move command
     * @param command user command
     * @return bool
     */
    bool checkMoveSyntax(std::string command);
    /**
     * @brief checkMoveLateral
     * Checks if a Lateral Move can be done
     * @param posStartLine Starting position
     * @param posEndLine End of line position
     * @param posEnd Arrival position
     * @return bool
     */
    bool checkMoveLateral(Position posStartLine,Position posEndLine,Position posEnd);
    /**
     * @brief checkMoveLine
     * Checks if a Line Move can be done
     * @param posStartLine Starting position
     * @param posEnd Arrival position
     * @return
     */
    bool checkMoveLine(Position posStartLine,Position posEnd);
    /**
     * @brief getLineEnd Used to get the end position for Move Line
     * @param posStartLine Starting position
     * @param posEnd Arrival position
     * @return Return the position of the last arriving square
     */
    Position getLineEnd(Position posStartLine,Position posEnd);
};

}
#endif // CONTROLLER_H
