#ifndef BOARD_H
#define BOARD_H

#include "main.h"
#include "square.h"

class Board
{
public:
    Board() {}
    square_t layout[3][4] = {
        {SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL},
        {SQUARE_NORMAL, SQUARE_HOLE, SQUARE_NORMAL, SQUARE_NORMAL},
        {SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL},
    };
    void init();
    void draw();
private:
    Square squares[3][4];
};

#endif // BOARD_H
