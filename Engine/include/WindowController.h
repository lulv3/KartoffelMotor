/* WINDOWCONTROLLER - TEST VERSION - 0.0.1*/

#pragma once

#include <imgui.h>
#include <imgui_impl_sdlrenderer2.h>
#include <imgui_impl_sdl2.h>
#include <vector>
#include <fstream>
#include <string>
#include <SDL.h>
#include <functional>

class WindowController
{
public:
    WindowController();
    ~WindowController();

    void Init(SDL_Window *window, SDL_Renderer *renderer);
    void Shutdown();
    void handleEvents(SDL_Event e);
    void render();
    int getRColor();
    int getGColor();
    int getBColor();
    void getSize();
    void setDebugMode(bool debugMode);

private:
    // Hier kannst du weitere ImGui-Elemente hinzufügen, die du benötigst

    bool isDebugMode;

    // Private Daten für WindowController
    bool m_checkbox;
    float m_slider;
    ImVec4 color = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
    ImVec2 guiSize;

    int width;
    int height;
};
