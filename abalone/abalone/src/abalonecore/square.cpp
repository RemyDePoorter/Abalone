#include "square.h"
using namespace abalone;

void Square::put(Status status){
    _status = status;
}

void Square::remove(){
    _status = Status::FREE;
}

bool Square::isFree(){
    return _status == Status::FREE;
}

bool Square::isMyOwn(PlayerColor color){
    return to_string(color) == to_string(_status);
}
bool Square::isOutside(){
    return _status == Status::OUTSIDE;
}

Status Square::getStatus(){
    return _status;
}
