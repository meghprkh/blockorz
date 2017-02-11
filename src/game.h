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
    square_t *layout;
    Board board;
    Cube cube1, cube2;
    int cube_r, cube_c;
    bool horizontal, horizontal_row;
    int nrows = 20, ncols = 20;
    square_t get_square(int r, int c);
};

#endif // GAME_H
