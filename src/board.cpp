#include "board.h"

void Board::init()
{
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 4; c++) {
            if (layout[r][c] != SQUARE_NORMAL) continue;
            squares[r][c].init();
            squares[r][c].set_position(r * 2, -1 - 0.05, c * -2);
        }
    }
}

void Board::draw() {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 4; c++) {
            squares[r][c].draw();
        }
    }
}
