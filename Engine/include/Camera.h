// Camera.h
#pragma once

#include <SDL.h>
#include "imgui.h"

class Camera
{
public:
    Camera(int screenWidth, int screenHeight);
    void update();
    void setViewport(int x, int y, int width, int height);
    void setZoom(float newZoom);
    void translate(int dx, int dy);
    void centerOn(int x, int y);
    void reset();
    void setImGuiVisibility(bool visible);
    void showCameraSettingsImGui();

private:
    SDL_Rect viewport;
    float zoom;
    int offsetX, offsetY;
    bool showCameraSettings; // For ImGui
};
