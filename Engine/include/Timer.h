#ifndef TIMER_H
#define TIMER_H

#include <SDL.h>

class Timer {
public:
    Timer();

    void update();
    float getDeltaTime() const;

private:
    Uint32 lastTime;
    float deltaTime;
};

#endif // TIMER_H
