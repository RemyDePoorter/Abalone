#include "game.h"
using namespace abalone;

Game::Game()
{
    _current = Player(PlayerColor::BLACK);
    _opponent = Player(PlayerColor::WHITE);

}
void Game::initialize(){
    _board = Board();

    //White
    for(int i = 0; i <= 1; i++){
        for (int j = 0; j <= 8 ; j++){
            if(_board.getSquare(Position(_board.getLetterCoord(i),_board.getIntCoord(j))).getStatus() != Status::OUTSIDE){
                _board.put(Position(_board.getLetterCoord(i),_board.getIntCoord(j)),Status::WHITE);
            }
        }

    }
    _board.put(Position('G',5),Status::WHITE);
    _board.put(Position('G',6),Status::WHITE);
    _board.put(Position('G',7),Status::WHITE);

    //Black
    for(int i = 8; i >= 7; i--){
        for (int j = 0; j <= 8 ; j++){
            if(_board.getSquare(Position(_board.getLetterCoord(i),_board.getIntCoord(j))).getStatus() != Status::OUTSIDE){
                _board.put(Position(_board.getLetterCoord(i),_board.getIntCoord(j)),Status::BLACK);
            }
        }

    }
    _board.put(Position('C',3),Status::BLACK);
    _board.put(Position('C',4),Status::BLACK);
    _board.put(Position('C',5),Status::BLACK);

}

void Game::moveLateral(Position posStartLine, Position posEndLine, Position posEnd){
    _board.moveLateral(posStartLine,posEndLine,posEnd);
}
void Game::moveLine(Position posStartLine, Position posEnd){
    _board.moveLine(posStartLine,posEnd);
}
void Game::removeBall(){
    _opponent.decrementNbBall();
}
void Game::swapPlayers(){
    Player tmp = _current;
    _current = _opponent;
    _opponent = tmp;
}
bool Game::isOver(){
    return _opponent.getNbBall() <= 8 || _current.getNbBall() <= 8;
}
bool Game::isInsidePos(Position position){
    return _board.isInsidePos(position);
}
bool Game::isMyOwn(Position position, PlayerColor color){
    return _board.isMyOwn(position,color);
}

bool Game::isFree(Position position){
    return _board.isFree(position);
}

bool Game::isOutside(Position position){
    return _board.isOutside(position);
}
Board Game::getBoard(){
    return _board;
}
Player Game::getCurrent(){
    return _current;
}
Player Game::getOpponent(){
    return _opponent;
}

PlayerColor Game::getWinner(){
    PlayerColor color = _opponent.getColor();
    if(_opponent.getNbBall()<= 8 && _current.getNbBall()>8){
        color = _current.getColor();
    }
    return color;
}
