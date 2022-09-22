#include "position.h"
using namespace abalone;

Position::Position(char x, int y):_x(x),_y(y){
}


char Position::getX(){
    return _x;
}

int Position::getY(){
    return _y;
}



