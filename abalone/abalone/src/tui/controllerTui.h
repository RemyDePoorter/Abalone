#ifndef CONTROLLERTUI_H
#define CONTROLLERTUI_H
#include "view.h"
#include "game.h"
#include "controller.h"

namespace abalone {
/**
 * @brief The Controller class
 * Created the dynamics of the game
 */
class ControllerTui : public Controller{
private:
    /*!
     * \brief _view
     * This attribute represent the view of our actual instance
     */
    View _view;

public:
    /**
     * @brief Controller
     * Initialize the attributes of the class
     * @param view
     * @param game
     */
    ControllerTui(View view, Game * game);
    /**
     * @brief initialize
     * Initializes the game by using the initialize() methods of its attributes
     */
    void initialize();
    /**
     * @brief startGame
     * Start a part of the game
     */
    void startGame();
    /**
     * @brief getView
     * @return Returns the _view attribute
     */
    View getView();
};

}
#endif // CONTROLLERTUI_H
