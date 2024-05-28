// CollisionDetection.h
#pragma once

#include <SDL.h>
#include "imgui.h"

class CollisionDetection
{
public:
    static bool checkCollision(SDL_Rect &rectA, SDL_Rect &rectB);
    static void drawDebugRect(SDL_Rect &rect, const ImVec4 &color = ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
    static bool showCollisionDebugUI(SDL_Rect &rectA, SDL_Rect &rectB);
};
