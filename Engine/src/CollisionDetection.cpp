// CollisionDetection.cpp
#include "CollisionDetection.h"

bool CollisionDetection::checkCollision(SDL_Rect &rectA, SDL_Rect &rectB)
{
    // Die Kollisionserkennung kann hier implementiert werden
    int leftA = rectA.x;
    int rightA = rectA.x + rectA.w;
    int topA = rectA.y;
    int bottomA = rectA.y + rectA.h;

    int leftB = rectB.x;
    int rightB = rectB.x + rectB.w;
    int topB = rectB.y;
    int bottomB = rectB.y + rectB.h;

    // Überlappen sich die Rechtecke?
    if (bottomA <= topB || topA >= bottomB || rightA <= leftB || leftA >= rightB)
    {
        return false; // Keine Kollision
    }
    else
    {
        return true; // Kollision
    }
}

void CollisionDetection::drawDebugRect(SDL_Rect &rect, const ImVec4 &color)
{
    ImGui::GetForegroundDrawList()->AddRect(
        ImVec2(static_cast<float>(rect.x), static_cast<float>(rect.y)),
        ImVec2(static_cast<float>(rect.x + rect.w), static_cast<float>(rect.y + rect.h)),
        ImColor(color));
}

bool CollisionDetection::showCollisionDebugUI(SDL_Rect &rectA, SDL_Rect &rectB)
{
    ImGui::Begin("Collision Debug");
    bool collision = checkCollision(rectA, rectB);
    ImGui::Text("Collision: %s", collision ? "true" : "false");
    ImGui::Separator();
    ImGui::Text("Rect A:");
    ImGui::Text("X: %d, Y: %d, W: %d, H: %d", rectA.x, rectA.y, rectA.w, rectA.h);
    ImGui::Text("Rect B:");
    ImGui::Text("X: %d, Y: %d, W: %d, H: %d", rectB.x, rectB.y, rectB.w, rectB.h);
    ImGui::End();
    return collision;
}
