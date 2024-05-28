#include "Input.h"

std::unordered_map<SDL_Keycode, bool> Input::m_keyStates;

void Input::Update() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            m_keyStates[event.key.keysym.sym] = true;
        }
        else if (event.type == SDL_KEYUP) {
            m_keyStates[event.key.keysym.sym] = false;
        }
    }
}

bool Input::IsKeyDown(SDL_Keycode key) {
    auto it = m_keyStates.find(key);
    return (it != m_keyStates.end()) ? it->second : false;
}

bool Input::IsKeyUp(SDL_Keycode key) {
    return !IsKeyDown(key);
}
