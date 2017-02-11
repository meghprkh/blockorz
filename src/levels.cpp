#include "main.h"

int nlevels = 2;

square_t levels[][400] = {
    {
        SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_HOLE, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
    },
    {
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NONE, SQUARE_NONE, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NONE, SQUARE_NONE, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NONE, SQUARE_NONE, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_HOLE, SQUARE_NORMAL, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NORMAL, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
        SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE, SQUARE_NONE,
    }
};

int levels_start[][2] = {
    {1, 1},
    {3, 1}
};