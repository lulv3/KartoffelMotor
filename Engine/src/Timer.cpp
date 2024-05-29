#include "Timer.h"
#include <iostream> // Für Debugging

Timer::Timer() : lastTime(SDL_GetTicks()), deltaTime(0.0f) {}

void Timer::update() {
    Uint32 currentTime = SDL_GetTicks();
    deltaTime = (currentTime - lastTime) / 100.0f; // Delta-Zeit in ms
    lastTime = currentTime;

    // Setzen Sie deltaTime auf einen minimalen Wert, um Null zu vermeiden
    if (deltaTime < 0.001f) {
        deltaTime = 0.001f;
    }

    // Debugging-Ausgabe, um die Delta-Zeit zu überprüfen
    // std::cerr << "DeltaTime: " << deltaTime << std::endl;
}

float Timer::getDeltaTime() const {
    return deltaTime;
}
