#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include <string>
#include <iomanip>
#include "player.h"
#include "board.h"

namespace abalone {
/**
 * @brief The View class
 * Interaction with the user
 */
class View{
public :
    /**
     * @brief View
     * Constructor who creates the view
     */
    View();
    /**
     * @brief displayBoard
     * @param board
     */
    void displayBoard(Board board);
    /**
     * @brief displayStart
     * Displays a welcome message to the user
     */
    void displayStart();
    /**
     * @brief displayQuit
     * Displays a goodbye message to the user
     */
    void displayQuit();
    /**
     * @brief displayHelp
     * Displays a list of possible commands
     */
    void displayHelp();
    /**
     * @brief displayOver Display who is the winner of the game
     * @param color of the player who win
     */
    void displayOver(PlayerColor color);
    /**
     * @brief displayCurrent
     * displays the current player who can play
     * @param color of the player
     */
    void displayCurrent(PlayerColor color);
    /**
     * @brief displayError
     * Displays an error message
     * @param msg displays the message received as a parameter
     */
    void displayError(std::string msg);
    /**
     * @brief askCommand
     * Displays a message asking the user to enter move command
     * @return string
     */
    std::string askCommand();
    /**
     * @brief toUpper
     * Put the received order in upper case
     * @param str
     */
    void toUpper(std::string & str);

};

}

#endif // VIEW_H
