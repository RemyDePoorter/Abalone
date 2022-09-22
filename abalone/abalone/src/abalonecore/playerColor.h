#ifndef PLAYERCOLOR_H
#define PLAYERCOLOR_H
#include <iostream>

namespace abalone {

/**
 * @brief The PlayerColor enum
 * This enumeration represent the color of player/ball
 */
enum class PlayerColor{
    WHITE, BLACK
};

/**
 * @brief to_string
 * @param color of the player
 * @return Transforming an enumeration PlayerColor into a string
 */
inline std::string to_string(PlayerColor color){
    std::string c;
    if(color==PlayerColor::WHITE){
        c = "WHITE";
    }else{
        c = "BLACK";
    }
    return c;
}

}

#endif // PLAYERCOLOR_H
