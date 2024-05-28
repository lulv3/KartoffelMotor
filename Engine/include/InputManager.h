#pragma once
#include <SDL.h>
#include <unordered_map>

class InputManager {
public:
    static void update();
    static bool isKeyDown(SDL_Keycode key);

private:
    static std::unordered_map<SDL_Keycode, bool> keyStates;
};
