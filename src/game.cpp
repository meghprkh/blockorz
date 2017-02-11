#include "game.h"

void Game::init() {
    board.init();
    cube1.init();
    cube2.init();

    cube_r = 0;
    cube_c = 1;
    horizontal = false;
    horizontal_row = false;
}

void Game::draw() {
    board.draw();
    cube1.position = glm::vec3(cube_r*2, 0, cube_c*-2);
    if (horizontal) {
        if (horizontal_row)
            cube2.position = glm::vec3(cube_r*2, 0, (cube_c+1)*-2);
        else
            cube2.position = glm::vec3((cube_r+1)*-2, 0, cube_c*-2);
    } else {
        cube2.position = glm::vec3(cube_r*2, 2, cube_c*-2);
    }
    cube1.draw();
    cube2.draw();
}
