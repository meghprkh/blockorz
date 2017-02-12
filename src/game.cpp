#include "game.h"

bool rox, roz;
int tox, toz, toy;
float rotating = 90;
int old_r, old_c;
bool old_horizontal, old_horizontal_row;

void Game::init() {
    if (level >= nlevels) {
        printf("Game Complete!\n");
        quit(window);
    }
    layout = levels[level];
    board.init(layout, nrows, ncols);
    cube1.init();
    cube2.init();

    cube_r = levels_start[level][0];
    cube_c = levels_start[level][1];
    horizontal = false;
    horizontal_row = false;
}

void Game::draw() {
    board.draw();
    glm::mat4 transform = glm::mat4(1.0f);
    if (rotating != 90) {
        glm::mat4 rottx, finalT;

        if (old_horizontal) {
            if (old_horizontal_row) {
                cube1.position = glm::vec3(0, 0, -1);
                cube2.position = glm::vec3(0, 0, 1);
                finalT = glm::translate(glm::vec3(0, 0, 1));
            } else {
                cube1.position = glm::vec3(-1, 0, 0);
                cube2.position = glm::vec3(1, 0, 0);
                finalT = glm::translate(glm::vec3(1, 0, 0));
            }
        } else {
            cube1.position = glm::vec3(0, 0, 0);
            cube2.position = glm::vec3(0, 2, 0);
        }

        glm::vec3 T = glm::vec3(-tox, 1, -toz);
        float rotatig = (tox > 0 || toz < 0) ? -rotating : rotating;
        if (roz) rottx = glm::rotate((float) (rotatig/180*M_PI), glm::vec3(0, 0, 1));
        else rottx = glm::rotate((float) (rotatig/180*M_PI), glm::vec3(1, 0, 0));

        transform *= glm::translate(-T) * rottx * glm::translate(T);
        transform = finalT * glm::translate(glm::vec3(old_r*2, 0, old_c*2)) * transform;

        cube1.draw(transform);
        cube2.draw(transform);

        rotating += 4.5;
    } else {
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
}

bool Game::move(direction_t dir) {
    old_r = cube_r; old_c = cube_c;
    old_horizontal = horizontal; old_horizontal_row = horizontal_row;
    rotating = 0;
    if (horizontal) {
        if (horizontal_row) {
            switch (dir) {
            case DIR_UP:
                cube_r += 1;
                rox = false; roz = true;
                tox = 1; toz = 0;
                break;
            case DIR_DOWN:
                cube_r -= 1;
                rox = false; roz = true;
                tox = -1; toz = 0;
                break;
            case DIR_LEFT:
                horizontal = horizontal_row = false;
                cube_c -= 1;
                rox = true; roz = false;
                tox = 0; toz = -2;
                break;
            case DIR_RIGHT:
                horizontal = horizontal_row = false;
                cube_c += 2;
                rox = true; roz = false;
                tox = 0; toz = 2;
                break;
            }
        } else {
            switch (dir) {
            case DIR_UP:
                horizontal = false;
                cube_r += 2;
                rox = false; roz = true;
                tox = 2; toz = 0;
                break;
            case DIR_DOWN:
                horizontal = false;
                cube_r -= 1;
                rox = false; roz = true;
                tox = -2; toz = 0;
                break;
            case DIR_LEFT:
                cube_c -= 1;
                rox = true; roz = false;
                tox = 0; toz = -1;
                break;
            case DIR_RIGHT:
                cube_c += 1;
                rox = true; roz = false;
                tox = 0; toz = 1;
                break;
            }
        }
    } else {
        horizontal = true;
        switch (dir) {
        case DIR_UP:
            cube_r += 1;
            horizontal_row = false;
            rox = false; roz = true;
            tox = 1; toz = 0;
            break;
        case DIR_DOWN:
            cube_r -= 2;
            horizontal_row = false;
            rox = false; roz = true;
            tox = -1; toz = 0;
            break;
        case DIR_LEFT:
            cube_c -= 2;
            horizontal_row = true;
            rox = true; roz = false;
            tox = 0; toz = -1;
            break;
        case DIR_RIGHT:
            cube_c += 1;
            horizontal_row = true;
            rox = true; roz = false;
            tox = 0; toz = 1;
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
            printf("Completed Level %d!\n", level+1);
            level++;
            init();
        } else if (h == SQUARE_NONE) return false;
    }
    return true;
}

square_t Game::get_square(int r, int c) {
    if (r >= nrows || c >= ncols || r < 0 || c < 0) return SQUARE_NONE;
    else return layout[r * nrows + c];
}
