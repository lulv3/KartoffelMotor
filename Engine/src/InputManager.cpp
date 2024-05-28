#include "InputManager.h"

std::unordered_map<SDL_Keycode, bool> InputManager::keyStates;

void InputManager::update() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            keyStates[event.key.keysym.sym] = true;
        }
        else if (event.type == SDL_KEYUP) {
            keyStates[event.key.keysym.sym] = false;
        }
    }
}

bool InputManager::isKeyDown(SDL_Keycode key) {
    auto it = keyStates.find(key);
    return it != keyStates.end() && it->second;
}
