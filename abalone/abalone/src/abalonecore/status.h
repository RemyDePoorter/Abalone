#ifndef STATUS_H
#define STATUS_H
#include <string>

namespace abalone {

/**
 * @brief The Status enum
 * This enumeration represent the status of a square
 */
enum class Status{
    FREE,OUTSIDE,WHITE,BLACK
};

/**
 * @brief to_string
 * @param status
 * @return Transforming an enumeration Status into a string
 */
inline std::string to_string(Status status){
    std::string s;
    if(status==Status::WHITE){
        s = "WHITE";
    }else if(status==Status::BLACK){
        s = "BLACK";
    }else if(status==Status::FREE){
        s = "FREE";
    }else {
        s = "OUTSIDE";
    }
    return s;
}

}

#endif // STATUS_H
