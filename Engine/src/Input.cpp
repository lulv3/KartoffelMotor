#include "Input.h"

std::unordered_map<SDL_Keycode, bool> Input::keyMap;
float Input::deltaTime = 0.0f;

void Input::Update(const SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        keyMap[event.key.keysym.sym] = true;
    }
}

bool Input::IsKeyDown(SDL_Keycode key) {
    return keyMap[key];
}

void Input::SetDeltaTime(float dt) {
    deltaTime = dt;
}

float Input::GetDeltaTime() {
    return deltaTime;
}
