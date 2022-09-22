#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "player.h"

namespace abalone {
/**
 * @brief The Game class
 */
class Game {
private:
    Board _board;
    Player _current;
    Player _opponent;

public:
    /**
     * @brief Game
     * Constructor who creates the game
     */
    Game();
    /**
     * @brief initialize
     * initialise the game board with the 28 balls
     */
    void initialize();
    /**
     * @brief moveLateral Uses the Board method
     * @param posStartLine
     * @param posEndLine
     * @param posEnd
     */
    void moveLateral(Position posStartLine, Position posEndLine, Position posEnd);
    /**
     * @brief moveLine Uses the Board method
     * @param posStartLine
     * @param posEnd
     */
    void moveLine(Position posStartLine, Position posEnd);
    /**
     * @brief removeBall
     * Decrement the number of balls of the opponent player
     */
    void removeBall();
    /**
     * @brief swapPlayers
     * This method exchanges the turn of the players
     */
    void swapPlayers();
    /**
     * @brief isOver
     * @return Checks if a game is finished
     */
    bool isOver();
    /**
     * @brief isInsidePos Uses the Board method
     * @param position
     * @return
     */
    bool isInsidePos(Position position);
    /**
     * @brief isMyOwn Uses the Board method
     * @param position
     * @param color
     * @return
     */
    bool isMyOwn(Position position, PlayerColor color);
    /**
     * @brief isFree Uses the Board method
     * @param position
     * @return
     */
    bool isFree(Position position);
    /**
      * @brief isOutside Uses the Board method
      * @param position
      * @return
      */
    bool isOutside(Position position);
    /**
     * @brief getBoard
     * @return returns the _board attribute
     */
    Board getBoard();
    /**
     * @brief getCurrent
     * @return returns the current player
     */
    Player getCurrent();
    /**
     * @brief getOpponent
     * @return returns the opponent player
     */
    Player getOpponent();
    /**
     * @brief getWinner
     * @return returns the winner of the game
     */
    PlayerColor getWinner();
};

}
#endif // GAME_H
