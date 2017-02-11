#ifndef SQUARE_H
#define SQUARE_H

#include "main.h"

class Square
{
public:
    Square() {}
    void init();
    void draw();
    void set_position(float x, float y, float z);
    glm::vec3 position;
private:
    VAO* object;
};

#endif // SQUARE_H
