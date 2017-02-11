#ifndef GAME_H
#define GAME_H

#include "main.h"
#include "board.h"
#include "cube.h"

class Game
{
public:
    Game() {}
    void init();
    void draw();
    bool move(direction_t dir);
private:
    square_t layout[3][4] = {
        {SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL},
        {SQUARE_NORMAL, SQUARE_HOLE, SQUARE_NORMAL, SQUARE_NORMAL},
        {SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL},
    };
    Board board;
    Cube cube1, cube2;
    int cube_r, cube_c;
    bool horizontal, horizontal_row;
    int nrows = 3, ncols = 4;
    square_t get_square(int r, int c);
};

#endif // GAME_H
