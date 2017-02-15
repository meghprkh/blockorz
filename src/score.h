#ifndef SCORE_H
#define SCORE_H

#include "digit.h"

class Score
{
public:
    Score();
    void draw();
    void update(int score);
    void add(int d = 1);
    void subtract(int d = 1);
private:
    int score, digslen;
    Digit digs[50];
};

#endif // SCORE_H
