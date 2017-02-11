#include "game.h"

void Game::init() {
    board.init(layout, nrows, ncols);
    cube1.init();
    cube2.init();

    cube_r = 0;
    cube_c = 1;
    horizontal = false;
    horizontal_row = false;
}

void Game::draw() {
    board.draw();
    cube1.position = glm::vec3(cube_r*2, 0, cube_c*2);
    if (horizontal) {
        if (horizontal_row)
            cube2.position = glm::vec3(cube_r*2, 0, (cube_c+1)*2);
        else
            cube2.position = glm::vec3((cube_r+1)*2, 0, cube_c*2);
    } else {
        cube2.position = glm::vec3(cube_r*2, 2, cube_c*2);
    }
    cube1.draw();
    cube2.draw();
}

bool Game::move(direction_t dir) {
    if (horizontal) {
        if (horizontal_row) {
            switch (dir) {
            case DIR_UP:
                cube_r += 1;
                break;
            case DIR_DOWN:
                cube_r -= 1;
                break;
            case DIR_LEFT:
                horizontal = horizontal_row = false;
                cube_c -= 1;
                break;
            case DIR_RIGHT:
                horizontal = horizontal_row = false;
                cube_c += 2;
                break;
            }
        } else {
            switch (dir) {
            case DIR_UP:
                horizontal = false;
                cube_r += 2;
                break;
            case DIR_DOWN:
                horizontal = false;
                cube_r -= 1;
                break;
            case DIR_LEFT:
                cube_c -= 1;
                break;
            case DIR_RIGHT:
                cube_c += 1;
                break;
            }
        }
    } else {
        horizontal = true;
        switch (dir) {
        case DIR_UP:
            cube_r += 1;
            horizontal_row = false;
            break;
        case DIR_DOWN:
            cube_r -= 2;
            horizontal_row = false;
            break;
        case DIR_LEFT:
            cube_c -= 2;
            horizontal_row = true;
            break;
        case DIR_RIGHT:
            cube_c += 1;
            horizontal_row = true;
            break;
        }
    }
    if (horizontal) {
        square_t h1, h2;
        if (horizontal_row) {
            h1 = get_square(cube_r, cube_c);
            h2 = get_square(cube_r, cube_c+1);
        } else {
            h1 = get_square(cube_r, cube_c);
            h2 = get_square(cube_r+1, cube_c);
        }
        if (h1 == SQUARE_NONE || h2 == SQUARE_NONE) return false;
    } else {
        square_t h = get_square(cube_r, cube_c);
        if (h == SQUARE_HOLE) {
            printf("Won!\n");
            quit(window);
        } else if (h == SQUARE_NONE) return false;
    }
    return true;
}

square_t Game::get_square(int r, int c) {
    if (r >= nrows || c >= ncols || r < 0 || c < 0) return SQUARE_NONE;
    else return layout[r * nrows + c];
}
