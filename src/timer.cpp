#include "timer.h"
#include "main.h"

Timer::Timer(double interval)
{
    prev = 0;
    this->interval = interval;
}

bool Timer::processTick()
{
    double cur = glfwGetTime();
    if (cur - prev >= interval) {
        prev = cur;
        return true;
    } else return false;
}
