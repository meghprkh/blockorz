#include "game.h"
#include "glm/ext.hpp"

bool rox, roz;
int tox, toz, toy;
float rotating = 90;
int old_r, old_c;
bool old_horizontal = false, old_horizontal_row = false;
int vfrot = 0, hfrot = 0;

bool bridge1 = false, bridge2 = false;

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

    old_r = cube_r;
    old_c = cube_c + 1;
    old_horizontal = old_horizontal_row = true;
    rotating = 90;
    rox = true; roz = false;
    tox = 0; toz = -2;

    score.update(0);
    life.init();
}

void Game::draw() {
    glm::mat4 transform = glm::mat4(1.0f);
    glm::mat4 rottx, finalT;
    glm::vec3 T, hfaxis, vfaxis;

    if (old_horizontal) {
        if (old_horizontal_row) {
            cube1.position = glm::vec3(0, 0, -1);
            cube2.position = glm::vec3(0, 0, 1);
            finalT = glm::translate(glm::vec3(0, 0, 1));
            hfaxis = glm::vec3(0, 0, 1);
            vfaxis = glm::vec3(1, 0, 0);
        } else {
            cube1.position = glm::vec3(-1, 0, 0);
            cube2.position = glm::vec3(1, 0, 0);
            finalT = glm::translate(glm::vec3(1, 0, 0));
            hfaxis = glm::vec3(1, 0, 0);
            vfaxis = glm::vec3(0, 0, 1);
        }
        T = glm::vec3(-tox, 1, -toz);
    } else {
        cube1.position = glm::vec3(0, -1, 0);
        cube2.position = glm::vec3(0, 1, 0);
        T = glm::vec3(-tox, 2, -toz);
        finalT = glm::translate(glm::vec3(0, 1, 0));
        hfaxis = glm::vec3(0, 1, 0);
        vfaxis = glm::vec3(1, 0, 0);
    }


    float rotatig = (tox > 0 || toz < 0) ? -rotating : rotating;
    if (roz) rottx = glm::rotate((float) (rotatig/180*M_PI), glm::vec3(0, 0, 1));
    else rottx = glm::rotate((float) (rotatig/180*M_PI), glm::vec3(1, 0, 0));

    transform = glm::rotate((float) (hfrot*M_PI/2), hfaxis) * transform;
    if (vfrot) transform = glm::scale(-2*hfaxis+glm::vec3(1, 1, 1)) * transform;
    transform = glm::translate(-T) * rottx * glm::translate(T) * transform;
    transform = finalT * glm::translate(glm::vec3(old_r*2, 0, old_c*2)) * transform;

    Matrices.view = glm::mat4(1.0f);
    if (camera_view == CAMERA_TOWER) {
        glm::vec3 eye ( 10*cos(camera_rotation_angle*M_PI/180.0f)-2, camera_y, 10*sin(camera_rotation_angle*M_PI/180.0f) + 11 );
        glm::vec3 target (0, 0, 11);
        glm::vec3 up (0, 1, 0);
        Matrices.view = glm::lookAt(eye, target, up);
    } else if (camera_view == CAMERA_FPS) {
        glm::vec3 eye = glm::vec3(transform * glm::vec4(cube2.position + glm::vec3(1, 0, 0), 1));
        glm::vec3 target = glm::vec3(transform * glm::vec4(cube2.position + glm::vec3(2, 0, 0), 1));
        glm::vec3 up (0, 1, 0);
        Matrices.view = glm::lookAt(eye, target, up);
    } else if (camera_view == CAMERA_FOLLOW) {
        glm::vec3 eye = glm::vec3(transform * glm::vec4(cube2.position, 1)) + glm::vec3(-4, 4, -4);
        glm::vec3 target = glm::vec3(transform * glm::vec4(cube2.position, 1));
        glm::vec3 up (0, 1, 0);
        Matrices.view = glm::lookAt(eye, target, up);
    } else if (camera_view == CAMERA_TOP) {
        glm::vec3 eye (10, 15, 10);
        glm::vec3 target (10, 0, 10);
        glm::vec3 up (1, 0, 0);
        Matrices.view = glm::lookAt(eye, target, up);
    } else if (camera_view == CAMERA_HELICOPTER) {
        glm::vec3 eye (10, 2, 10);
        glm::vec3 target ( 10*cos(camera_look_x*M_PI/180.0f)*sin(camera_look_y*M_PI/180.0f), 10*cos(camera_look_y*M_PI/180.0f), 10*sin(camera_look_x*M_PI/180.0f)*sin(camera_look_y*M_PI/180.0f) );
        // cout << camera_look_x << ' ' << camera_look_y << ' ' << glm::to_string(target) << endl;
        glm::vec3 up (1, 1, 1);
        Matrices.view = glm::lookAt(eye, target, up);
    }

    VP = Matrices.view * glm::scale(glm::vec3(exp(camera_zoom)));
    if (camera_ortho) VP = Matrices.projectionO * VP;
    else VP = Matrices.projectionP * VP;

    board.draw();
    score.draw();
    life.draw();
    cube1.draw(transform);
    cube2.draw(transform);

    if (rotating != 90) rotating += 4.5;
}

bool Game::move(direction_t dir) {
    score.add();
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
                hfrot++;
                break;
            case DIR_DOWN:
                cube_r -= 1;
                rox = false; roz = true;
                tox = -1; toz = 0;
                hfrot--;
                break;
            case DIR_LEFT:
                horizontal = horizontal_row = false;
                cube_c -= 1;
                rox = true; roz = false;
                tox = 0; toz = -2;
                vfrot++;
                break;
            case DIR_RIGHT:
                horizontal = horizontal_row = false;
                cube_c += 2;
                rox = true; roz = false;
                tox = 0; toz = 2;
                vfrot++;
                break;
            }
        } else {
            switch (dir) {
            case DIR_UP:
                horizontal = false;
                cube_r += 2;
                rox = false; roz = true;
                tox = 2; toz = 0;
                vfrot++;
                break;
            case DIR_DOWN:
                horizontal = false;
                cube_r -= 1;
                rox = false; roz = true;
                tox = -2; toz = 0;
                vfrot++;
                break;
            case DIR_LEFT:
                cube_c -= 1;
                rox = true; roz = false;
                tox = 0; toz = -1;
                hfrot--;
                break;
            case DIR_RIGHT:
                cube_c += 1;
                rox = true; roz = false;
                tox = 0; toz = 1;
                hfrot++;
                break;
            }
        }
    } else {
        horizontal = true;
        switch (dir) {
        vfrot++;
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
    hfrot %= 4;
    vfrot %= 2;
    // printf("%d %d\n", vfrot, hfrot);
    // fflush(stdout);
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
        else if (!bridge1 && (h1 == SQUARE_B1 || h2 == SQUARE_B1)) return false;
        else if (!bridge2 && (h1 == SQUARE_B2 || h2 == SQUARE_B2)) return false;
        else if (h1 == SQUARE_B1SO || h2 == SQUARE_B1SO) bridge1 = !bridge1;
        else if (h1 == SQUARE_B2SO || h2 == SQUARE_B2SO) bridge2 = !bridge2;
    } else {
        square_t h = get_square(cube_r, cube_c);
        if (h == SQUARE_HOLE) {
            printf("Completed Level %d!\n", level+1);
            level++;
            init();
        } else if (h == SQUARE_NONE || h == SQUARE_WEAK) return false;
        else if (!bridge1 && h == SQUARE_B1) return false;
        else if (!bridge2 && h == SQUARE_B2) return false;
        else if (h == SQUARE_B1SX || h == SQUARE_B1SO) bridge1 = !bridge1;
        else if (h == SQUARE_B2SX || h == SQUARE_B2SO) bridge2 = !bridge2;
    }
    return true;
}

square_t Game::get_square(int r, int c) {
    if (r >= nrows || c >= ncols || r < 0 || c < 0) return SQUARE_NONE;
    else return layout[r * nrows + c];
}

void Game::lose() {
    if (life.decrease()) { quit(window); }
    this->init();
}
