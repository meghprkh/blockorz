#ifndef GAME_H
#define GAME_H

#include "main.h"
#include "board.h"
#include "cube.h"
#include "score.h"
#include "life.h"

class Game
{
public:
    Game() {}
    void init(int cube_r, int cube_c);
    void init();
    void draw();
    bool move(direction_t dir);
    void lose();
private:
    square_t *layout;
    Board board;
    Cube cube1, cube2;
    int cube_r, cube_c;
    bool horizontal, horizontal_row;
    int nrows = 20, ncols = 20;
    square_t get_square(int r, int c);
    int level = 0;
    Score score;
    Life life;
};

#endif // GAME_H
