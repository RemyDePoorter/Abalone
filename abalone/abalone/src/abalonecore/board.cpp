#include "board.h"
#include <memory>

using namespace abalone;

Board::Board(){
    //Tout le board à free
    for(int i = 0 ; i < _row; i++){
        for(int j = 0 ; j < _column; j++){
            _squares[i][j] = *std::make_unique<Square>(); // voir constructeur par défaut Square
        }
    }
    // Mise en place des cases outsides en haut à gauche du board
    for(int i = 0; i < 4 ; i++){
        for(int j = 0 ; j < 4 - i ; j++){
            _squares[i][j].put(Status::OUTSIDE);
        }
    }
    // Mise en place des cases outsides en bas à droite du board
    for(int i = 5; i < _row ; i++){
        for(int j = 13 - i ; j < _column ; j++){
            _squares[i][j].put(Status::OUTSIDE);
        }
    }
}
void Board::put(Position position, Status status){
    _squares[getRowCoord(position.getX())][getColumnCoord(position.getY())].put(status);
}
void Board::remove(Position position){
    _squares[getRowCoord(position.getX())][getColumnCoord(position.getY())].put(Status::FREE);
}
bool Board::isInsideTab(int row, int column){
    return  row >= 0 && row <= 8 && column >= 0 && column <= 8;
}
bool Board::isInsidePos(Position position){
    return position.getX() >= 'A' && position.getX() <= 'I' && position.getY() >= 1 && position.getY() <= 9;
}
bool Board::isFree(Position position){
    return _squares[getRowCoord(position.getX())][getColumnCoord(position.getY())].isFree();
}
bool Board::isMyOwn(Position position, PlayerColor color){
    return _squares[getRowCoord(position.getX())][getColumnCoord(position.getY())].isMyOwn(color);
}
bool Board::isOutside(Position position){
    return _squares[getRowCoord(position.getX())][getColumnCoord(position.getY())].isOutside();
}
int Board::getRow(){
    return _row;
}
int Board::getColumn(){
    return _column;
}
Square Board::getSquare(Position position){
    return _squares[getRowCoord(position.getX())][getColumnCoord(position.getY())];
}
void Board::moveLateral(Position posStartLine, Position posEndLine, Position posEnd){
    std::pair <int,int> line = {posEndLine.getX()-posStartLine.getX(),posEndLine.getY()-posStartLine.getY()};//Permet d'avoir la direction de la ligne qu'on souhaite déplacer
    std::pair <int,int> move = {posEnd.getX()-posStartLine.getX(),posEnd.getY()-posStartLine.getY()};//Dans quelle direction vont se déplacer les balles
    line.first=line.first==2?1:line.first;//S'il y a 2 boules en plus de celle de départ à déplacer, on le remplace par 1 pour avoir la balle intermédiaire
    line.second=line.second==2?1:line.second;//comme un else if
    Position pos = posStartLine;
    while(pos.getX()<= posEndLine.getX() && pos.getY()<= posEndLine.getY()){//itération sur toutes les balles et on les déplace
        Status statusPos = getSquare(pos).getStatus();
        Position posNext=Position(char(pos.getX()+move.first),pos.getY()+move.second);
        put(posNext,statusPos);
        remove(pos);
        pos=Position(char(pos.getX()+line.first), pos.getY()+line.second);
    }
}
void Board::moveLine(Position posStartLine, Position posEnd){
    //posEnd est la position d'arrivée pour la dernière balle
    std::pair <int,int> move = {posEnd.getX()-posStartLine.getX(),posEnd.getY()-posStartLine.getY()};
    move.first = (move.first > 0) - (move.first < 0);//Dans quelle direction vont se déplacer les balles(Coordonnée char ABA-PRO)
    move.second = (move.second > 0) - (move.second < 0);//Dans quelle direction vont se déplacer les balles(Coordonnée int ABA-PRO)
    Status status = getSquare(posStartLine).getStatus();
    Status save;
    Position pos = posStartLine;
    remove(pos);
    while(!(pos.getX()==posEnd.getX() && pos.getY()== posEnd.getY())){
        Position nextPos =Position(char(pos.getX()+move.first),pos.getY()+move.second);
        save=getSquare(nextPos).getStatus();
        if(isInsidePos(nextPos) && !isOutside(nextPos)){
            put(nextPos,status);
        }
        pos=nextPos;
        status = save;
    }

}
int Board::getRowCoord(char coordLetter){//ok Transformer A (A1) en coordonnée [ici][] // ABA-PRO vers [ici][]
    int row = 0;
    if(coordLetter >= 'A' && coordLetter <='I'){
        row = 'I' - coordLetter;
    }
    return row;
}
int Board::getColumnCoord(int coordInt){ // Transformer 1 (A1) en coordonnée [][ici] // ABA-PRO vers [][ici]
    int column = 0;
    if(coordInt >= 1 && coordInt <= 9){
        column = coordInt - 1 ;
    }
    return column;
}
char Board::getLetterCoord(int i){//[ici][] vers ABA-PRO
    return 'I' - char(i);
}
int Board::getIntCoord(int j){//[][ici] vers ABA-PRO
    return j + 1;
}

