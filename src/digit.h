#ifndef DIGIT_H
#define DIGIT_H

#include "main.h"
#include "line.h"


class Digit
{
public:
    Digit() {}
    Digit(char c, float x, float y);
    glm::vec3 position;
    void draw();
    void set_position(float x, float y);
private:
    Line lines[7];
};

#endif // DIGIT_H
