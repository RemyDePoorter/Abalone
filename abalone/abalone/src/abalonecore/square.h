#ifndef SQUARE_H
#define SQUARE_H
#include "status.h"
#include "position.h"
#include "playerColor.h"

namespace abalone {
/**
 * @brief The Square class
 * Represents a square on the game board
 */
class Square{
private:
    Status _status;

public:
    /**
     * @brief Square
     * Default Constructor + default value
     * @param status
     */
    Square(Status status = Status::FREE) : _status(status) {}
    /**
     * @brief put
     * Changes the status of a square from the status received in parameter
     * @param status
     */
    void put(Status status);
    /**
     * @brief remove
     * Change the status of a square to free status
     */
    void remove();
    /**
     * @brief isFree
     * @return Check if this square is free
     */
    bool isFree();
    /**
     * @brief isMyOwn
     * Check if the status on the square has the same color as the one given in
     * parameter
     * @param color of the player
     * @return
     */
    bool isMyOwn(PlayerColor color);
    /**
     * @brief isOutside Check if this square is Outside
     * @return
     */
    bool isOutside();
    /**
     * @brief getStatus
     * @return returns the _status attribute of the square.
     */
    Status getStatus();
};

}
#endif // SQUARE_H
