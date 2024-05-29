#ifndef INPUT_H
#define INPUT_H

#include <unordered_map>
#include <SDL.h>

class Input {
public:
    static void Update(const SDL_Event& event);
    static bool IsKeyDown(SDL_Keycode key);
    static void SetDeltaTime(float dt);
    static float GetDeltaTime();

private:
    static std::unordered_map<SDL_Keycode, bool> keyMap;
    static float deltaTime;
};

#endif // INPUT_H
