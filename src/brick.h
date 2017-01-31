#ifndef BRICK_H
#define BRICK_H

#include "main.h"

class Brick
{
public:
    Brick() {}
    Brick(brick_color_t color, float speed = 0.025);
    brick_color_t color;
    glm::vec3 position;
    void draw();
    void set_position(float x, float y);
    void tick();
    float speed;
private:
    VAO* object;
};

#endif // BRICK_H
