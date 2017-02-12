#ifndef CUBE_H
#define CUBE_H

#include "main.h"

class Cube
{
public:
    Cube() {}
    void init();
    void draw(glm::mat4 transform = glm::mat4(1.0f));
    void set_position(float x, float y, float z);
    glm::vec3 position;
private:
    VAO* object;
};

#endif // CUBE_H
