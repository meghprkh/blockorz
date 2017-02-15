#include "score.h"
#include "main.h"
#include <cstring>

Score::Score()
{
    score = 0;
    digslen = 0;
}

void Score::update(int score) {
    this->score = score;
    char scorestr[50];
    sprintf(scorestr, "%d", score);
    digslen = strlen(scorestr);
    for (int i = digslen - 1; i >= 0; i--) {
        digs[i] = Digit(scorestr[i], 20 - 0.7*(digslen - i), 7.5);
    }
}

void Score::add(int d) {
    update(score+d);
}

void Score::subtract(int d) {
    update(score-d);
}

void Score::draw() {
    for (int i = 0; i < digslen; i++) digs[i].draw();
}
