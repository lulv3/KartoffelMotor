#pragma once

#include <SDL.h>
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"
#include <string>
#include "Sprite.h"

class EngineGUI
{
public:
    EngineGUI();
    ~EngineGUI();

    void initialize(SDL_Window *window, SDL_Renderer *renderer);
    void newFrame();
    void render();
    void shutdown();
    void handleImGuiEvents(SDL_Event &event);

    // Details Panel
    void drawDetailsPanel();
    void updateSelectedObject(Sprite *selectedSprite);
    void handleMouseClick(int mouseX, int mouseY, std::vector<Sprite *> &sprites);

    // Window Controller

    void drawWindowController();
    int getRColor();
    int getGColor();
    int getBColor();
    void getSize();
    void setDebugMode(bool debugMode);

private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;

    std::string m_selectedObjectName;
    std::string m_selectedObjectType;

    bool dockingEnabled = true;

    // Window Controller
    bool isDebugMode;

    // Private Daten für WindowController
    bool wc_checkbox;
    float wc_slider;
    ImVec4 wc_color = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
    ImVec2 wc_guiSize;

    int wc_width;
    int wc_height;
};
