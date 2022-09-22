#include "controllerTui.h"

using namespace abalone;

ControllerTui::ControllerTui(View view, Game * game):Controller(game), _view(view){

}

void ControllerTui::initialize(){
    _view.displayStart();
    _game->initialize();
}

void ControllerTui::startGame(){
    initialize();
    _view.displayHelp();
    while(!_game->isOver()){
        _view.displayBoard(_game->getBoard());
        _view.displayCurrent(_game->getCurrent().getColor());

        std::string command;
        bool valid = false;
        while(!valid){
            command = _view.askCommand();
            valid = true;
            if(command == "QUIT"){
                _view.displayOver(_game->getOpponent().getColor());
                _view.displayQuit();
                exit(3);
            }else if(command == "HELP") {
                _view.displayHelp();
            }else{
                valid = checkMoveSyntax(command);

                if(valid && command.size()== 4){ // Move Line
                    Position posStartLine = Position(command[0],Position::to_int(command[1]));
                    Position posEnd = Position(command[2],Position::to_int(command[3]));
                    valid=checkMoveLine(posStartLine,posEnd);
                    if(valid){
                        Position currentPos = getLineEnd(posStartLine,posEnd);//donne la position d'arrivé de la dernière balle
                        if(!_game->isInsidePos(currentPos) || _game->isOutside(currentPos)){
                            _game->removeBall();
                            //std::cout<<"Une balle ennemie a ete poussee"<<std::endl;
                        }
                        _game->moveLine(posStartLine,currentPos);
                        _game->swapPlayers();
                    }

                }else if(valid && command.size()==6){//Move Lateral
                    Position posStartLine = Position(command[0],Position::to_int(command[1]));
                    Position posEndLine = Position(command[2],Position::to_int(command[3]));
                    Position posEnd = Position(command[4],Position::to_int(command[5]));
                    valid = checkMoveLateral(posStartLine,posEndLine,posEnd);
                    if(valid){
                        _game->moveLateral(posStartLine,posEndLine,posEnd);
                        _game->swapPlayers();
                    }
                }
            }
            if(!valid){
                _view.displayError("Command Invalid");
            }
            std::cout << std::endl;
        }
    }
    _view.displayBoard(_game->getBoard());
    _view.displayOver(_game->getWinner());
}

View ControllerTui::getView(){
    return _view;
}

