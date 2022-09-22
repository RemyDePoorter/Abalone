#ifndef PLAYER_H
#define PLAYER_H
#include "playerColor.h"

namespace abalone {
/**
 * @brief The Player class
 * Represents a player of the game, they are differentiated by their colour
 */
class Player{

private:
    /**
     * @brief nbBallRemaining
     * This attribute represent the number of ball of our player.
     */
    int _nbBallRemaining = 14;
    /**
     * @brief color
     * This attribute represent the color of our player.
     */
    PlayerColor _color;

public:
    /**
     * @brief Player
     * Default Constructor + default value
     * @param color
     */
    Player(PlayerColor color = PlayerColor::BLACK) : _color(color){}

    /**
     * @brief decrementNbBall, remove a ball of our player.
     * @param nbBallRemmaining
     */
    void decrementNbBall();

    /**
     * @brief getNbBall
     * @return the number of ball of our player
     */
    int getNbBall();

    /**
     * @brief getColor
     * @return the color of our player
     */
    PlayerColor getColor();

};

}

#endif // PLAYER_H
