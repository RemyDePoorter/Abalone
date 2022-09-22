#ifndef POSITION_H
#define POSITION_H

namespace abalone {
/**
 * @brief The Position class
 * This class represent a position on our board
 */
class Position {

private:

    /*!
     * \brief x
     * This attribute represent the row(letter) of our position ABA-PRO
     */
    char _x;

    /*!
     * \brief y
     * This attribute represent the column(number) of our position ABA-PRO
     */
    int _y;

public:

    /*!
     * \brief Position
     * \param x the row of the position we create
     * \param y the column of the position we create
     */
    Position(char x, int y);

    /**
     * @brief getX
     * @return x the letter in a position
     */
    char getX();

    /**
     * @brief getY
     * @return y the number in a position
     */
    int getY();
    /**
     * @brief to_int
     * Allows you to switch from an Ascii character to an int character
     * @param c
     * @return int
     */
    inline static int to_int(char c){
        return c-'0';
    }

};

}
#endif // POSITION_H
