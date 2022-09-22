#ifndef BOARD_H
#define BOARD_H
#include "position.h"
#include "player.h"
#include "square.h"

namespace abalone {
/**
 * @brief The Board class
 * Represents the game board
 */
class Board{
private:
    Square _squares[9][9];
    int _column = 9;
    int _row = 9;

    /**
     * @brief getRowCoord
     * @param coordLetter represents the letter of the ABA-PRO coordinate
     * @return the row of the board -- > [here][] (0->8)
     */
    int getRowCoord(char coordLetter);
    /**
     * @brief getColumnCoord
     * @param coordInt represents the number of the ABA-PRO coordinate
     * @return the column of the board --> [][here] (0->8)
     */
    int getColumnCoord(int coordInt);

public:
    /**
     * @brief Board
     * Represents the constructor that creates the board.
     */
    Board();
    /**
     * @brief put
     * Change the status at a given position using the received parameter(status)
     * @param position An ABA-PRO coordinate
     * @param status
     */
    void put(Position position, Status status);
    /**
     * @brief remove
     * Changes the status of a cell to status free at a given position
     * @param position An ABA-PRO coordinate
     */
    void remove(Position position);
    /**
     * @brief isInsideTab
     * Checks if a [][] coordinate exists on the board
     * @param row [here][]
     * @param column [][here]
     * @return true if the coordinate exists on the board
     */
    bool isInsideTab(int row, int column);
    /**
     * @brief isInsidePos
     * Checks if an Aba-pro coordinate exists on the board
     * @param position An ABA-PRO coordinate
     * @return true if, for example, A1 is in the board.
     */
    bool isInsidePos(Position position);
    /**
     * @brief isFree
     * Checks if at a given position the status of the square is free
     * @param position An ABA-PRO coordinate
     * @return true if status is free
     */
    bool isFree(Position position);
    /**
     * @brief isMyOwn
     * Checks if at a given position the status of the square
     * is the same as the colour of the player received in parameter
     * @param position An ABA-PRO coordinate
     * @param color of the player
     * @return true is the status and the color is the same
     */
    bool isMyOwn(Position position, PlayerColor color);
    /**
     * @brief isOutside Checks if at a given position the status of the square is outside
     * @param position An ABA-PRO coordinate
     * @return true if status is outside
     */
    bool isOutside(Position position);
    /**
     * @brief getSquare
     * Returns the board square from a received ABA-PRO coordinate
     * @param positon An ABA-PRO coordinate
     */
    Square getSquare(Position positon);
    /**
     * @brief moveLateral Allows you to make a lateral movement of 1 to 3 balls
     * @param posStartLine Position of the 1st ball of the selected line
     * @param posEndLine Position of the last ball of the selected line
     * @param posEnd Arrival position of the 1st ball whose other ball(s) will make the same movement as the 1st ball
     */
    void moveLateral(Position posStartLine, Position posEndLine, Position posEnd);
    /**
     * @brief moveLine Allows to move or push 1 or 3 balls
     * @param posStartLine selection of the starting position
     * @param posEnd selection of the arrival position
     */
    void moveLine(Position posStartLine, Position posEnd);
    /**
     * @brief getLetterCoord
     * @param i
     * @return Transforms a row coordinate [here][] into a letter to get an ABA-PRO coordinate(A->I)
     */
    char getLetterCoord(int i);
    /**
     * @brief getIntCoord
     * @param j
     * @return Transforms a column coordinate [here][] into a number to get an ABA-PRO coordinate(1->9)
     */
    int getIntCoord(int j);
    /**
     * @brief getRow
     * @return returns the attribute _row which is the number of lines in the board.
     */
    int getRow();
    /**
     * @brief getColumn
     * @return returns the _column attribute which is the number of columns in the board.
     */
    int getColumn();

};

}
#endif // BOARD_H
