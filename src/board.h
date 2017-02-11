#ifndef BOARD_H
#define BOARD_H

#include "main.h"
#include "square.h"

class Board
{
public:
    Board() {}
    void init(square_t *layout, int nrows, int ncols);
    void draw();
private:
    Square squares[50][50];
};

#endif // BOARD_H
