#include "board.h"

void Board::init(square_t *layout, int nrows, int ncols) {
    this->layout = layout;
    this->nrows = nrows;
    this->ncols = ncols;
    for (int r = 0; r < nrows; r++) {
        for (int c = 0; c < ncols; c++) {
            squares[r][c].init(layout[r * nrows + c]);
            squares[r][c].set_position(r * 2, -1 - 0.05, c * 2);
        }
    }
}

void Board::draw() {
    for (int r = 0; r < nrows; r++) {
        for (int c = 0; c < ncols; c++) {
            squares[r][c].draw();
        }
    }
}
