#ifndef SQUARE_H
#define SQUARE_H

#include "main.h"

class Square
{
public:
    Square() {}
    void init(square_t type);
    void draw();
    void set_position(float x, float y, float z);
    glm::vec3 position;
private:
    VAO* object = NULL;
    VAO* object_edge = NULL;
    square_t type;
};

#endif // SQUARE_H
