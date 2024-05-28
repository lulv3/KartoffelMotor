#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>
#include <unordered_map>

class Input {
public:
    static void Update();

    static bool IsKeyDown(SDL_Keycode key);
    static bool IsKeyUp(SDL_Keycode key);

private:
    static std::unordered_map<SDL_Keycode, bool> m_keyStates;
};

#endif // INPUT_H
