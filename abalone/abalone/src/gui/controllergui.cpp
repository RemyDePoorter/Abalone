#include "controllergui.h"

using namespace abalone;

controllerGui::controllerGui(Game * game, AppBoard * appBoard): Controller(game), _appBoard(appBoard)
{

}

bool controllerGui::makeMove(){
    std::string command = _appBoard->getMove();
    bool valid = checkMoveSyntax(command);
    if(!_game->isOver()){
        if(valid && command.size()== 4){ // Move Line
            Position posStartLine = Position(command[0],Position::to_int(command[1]));
            Position posEnd = Position(command[2],Position::to_int(command[3]));
            valid=checkMoveLine(posStartLine,posEnd);
            if(valid){
                Position currentPos = getLineEnd(posStartLine,posEnd);//donne la position d'arrivé de la dernière balle
                if(!_game->isInsidePos(currentPos) || _game->isOutside(currentPos)){
                    _game->removeBall();
                }
                _game->moveLine(posStartLine,currentPos);
                _appBoard->update();
                _game->swapPlayers();
            }
        }else if(valid && command.size()==6){//Move Lateral
            Position posStartLine = Position(command[0],Position::to_int(command[1]));
            Position posEndLine = Position(command[2],Position::to_int(command[3]));
            Position posEnd = Position(command[4],Position::to_int(command[5]));
            valid = checkMoveLateral(posStartLine,posEndLine,posEnd);
            if(!valid){
                posStartLine = Position(command[4],Position::to_int(command[5]));
                posEndLine = Position(command[0],Position::to_int(command[1]));
                posEnd = Position(command[2],Position::to_int(command[3]));
                valid = checkMoveLateral(posStartLine,posEndLine,posEnd);
            }
            if(!valid){
                posStartLine = Position(command[2],Position::to_int(command[3]));
                posEndLine = Position(command[4],Position::to_int(command[5]));
                posEnd = Position(command[0],Position::to_int(command[1]));
                valid = checkMoveLateral(posStartLine,posEndLine,posEnd);
            }
            if(valid){
                _game->moveLateral(posStartLine,posEndLine,posEnd);
                _appBoard->update();
                _game->swapPlayers();
            }
        }
    }
    return valid;
}




