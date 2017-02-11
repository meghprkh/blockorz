#include "board.h"

void Board::init(square_t *layout, int nrows, int ncols) {
    for (int r = 0; r < nrows; r++) {
        for (int c = 0; c < ncols; c++) {
            if (layout[r * nrows + c] != SQUARE_NORMAL) continue;
            squares[r][c].init();
            squares[r][c].set_position(r * 2, -1 - 0.05, c * 2);
        }
    }
}

void Board::draw() {
    for (int r = 0; r < 50; r++) {
        for (int c = 0; c < 50; c++) {
            squares[r][c].draw();
        }
    }
}
