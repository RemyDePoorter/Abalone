#include "controller.h"

using namespace abalone;

bool Controller::checkMoveSyntax(std::string command){
    bool valid = true;
    if(command.size() != 4 && command.size() != 6){
        valid = false;
    }else{
        for(unsigned i = 0 ; i < command.size();i++){
            if(i%2==0){//on check les lettres
                if(!(command[i] >= 'A' && command[i] <= 'I')){
                    valid = false;
                }
            }else{//on check les chiffres
                if(!(command[i]>= '1' && command[i] <= '9')){
                    valid = false;
                }
            }
        }
    }
    return valid;
}

bool Controller::checkMoveLateral(Position posStartLine,Position posEndLine,Position posEnd){
    bool valid = true;
    std::pair <int,int> line = {posEndLine.getX()-posStartLine.getX(),posEndLine.getY()-posStartLine.getY()};//Permet d'avoir la direction de la ligne qu'on souhaite déplacer
    std::pair <int,int> move = {posEnd.getX()-posStartLine.getX(),posEnd.getY()-posStartLine.getY()};//Dans quelle direction vont se déplacer les balles
    if((move.first==-1 && move.second==1)||(move.first==1 && move.second==-1)){
        valid = false;
    }
    if(abs(move.first) > 1 || abs(move.second)>1){//abs = valeur absolue // vérification du cas où on déplace une balle de plusieurs cases au lieu de 1 case
        valid = false;
    }
    if(!(line.first>=0 && line.first<=2 && line.second>=0 && line.second<=2)||(line.first==0 && line.second==0)){//Le joueur ne peut pas déplacer plus de 2 balles en plus que celle de départ.Ni lui même en Move Lateral
        valid=false;
    }
    line.first=line.first==2?1:line.first;//S'il y a 2 boules en plus de celle de départ à déplacer, on le remplace par 1 pour avoir la balle intermédiaire
    line.second=line.second==2?1:line.second;//idem
    Position pos = posStartLine;
    while(valid && pos.getX()<=posEndLine.getX() && pos.getY()<=posEndLine.getY()){
        Position dest = Position(char(pos.getX()+move.first),pos.getY()+move.second);
        if(!(_game->isInsidePos(pos)&&_game->isInsidePos(dest)&&_game->isFree(dest)
             && _game->isMyOwn(pos,_game->getCurrent().getColor()))){
            valid=false;
        }
        pos=Position(char(pos.getX()+line.first),pos.getY()+line.second);
    }
    return valid;
}

bool Controller::checkMoveLine(Position posStartLine,Position posEnd){
    bool valid = true;
    std::pair <int,int> command = {posEnd.getX()-posStartLine.getX(),posEnd.getY()-posStartLine.getY()};
    if((command.first == -1 && command.second == 1)||(command.first == 1 && command.second == -1)){
        valid = false;
    }
    if(abs(command.first) > 1 || abs(command.second)>1 ||(command.first==0 && command.second==0)){//abs = valeur absolue // vérification du cas où on déplace une balle de plusieurs cases au lieu de 1 case
        valid = false;
    }
    Position currentPos = posStartLine;
    int nbCurrent=0;
    int nbOpponent=0;
    if(valid){
        if(_game->isInsidePos(posStartLine) && _game->isInsidePos(posEnd)&& _game->isMyOwn(posStartLine,_game->getCurrent().getColor())){//vérifie que la case de départ nous appartient
            while(_game->isInsidePos(currentPos)&&_game->isMyOwn(currentPos,_game->getCurrent().getColor())){//compte le nbr de boule allié
                nbCurrent++;
                currentPos = Position(char(currentPos.getX()+command.first) ,currentPos.getY()+command.second);
            }
            if(nbCurrent>3){
                valid = false;
            }else{
                if(!_game->isInsidePos(currentPos)|| (!_game->isFree(currentPos) &&_game->isOutside(currentPos))){// vérifie la case après les alliés .
                    valid=false;
                }else{
                    while(_game->isInsidePos(currentPos)&&_game->isMyOwn(currentPos,_game->getOpponent().getColor())){//compte le nbr de boule ennemi
                        nbOpponent++;
                        currentPos = Position(char(currentPos.getX()+command.first) ,currentPos.getY()+command.second);
                    }

                    if(nbCurrent <= nbOpponent || _game->isMyOwn(currentPos,_game->getCurrent().getColor())){//vérifie que le nbr de boule nbCurrent peut pousser le nbr de boule nbOpponent
                        valid=false;
                    }
                }
            }
        }else{
            valid=false;
        }
    }
    return valid;
}

Position Controller::getLineEnd(Position posStartLine,Position posEnd){
    std::pair <int,int> command = {posEnd.getX()-posStartLine.getX(),posEnd.getY()-posStartLine.getY()};
    Position currentPos= posStartLine;
    while(_game->isInsidePos(currentPos)&& !_game->isFree(currentPos) &&! _game->isOutside(currentPos)){
        currentPos = Position(char(currentPos.getX()+command.first) ,currentPos.getY()+command.second);
    }

    return currentPos;
}
