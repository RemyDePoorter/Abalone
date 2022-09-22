#include "player.h"
using namespace abalone;

void Player::decrementNbBall(){
    _nbBallRemaining--;
}

int Player::getNbBall(){
    return _nbBallRemaining;
}

PlayerColor Player::getColor(){
    return _color;
}
