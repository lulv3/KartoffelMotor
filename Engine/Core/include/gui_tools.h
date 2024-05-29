#ifndef GUI_TOOLS_H
#define GUI_TOOLS_H

#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>
#include <SDL.h>

class GuiTools
{
public:
    static void Init(SDL_Window* window, SDL_Renderer* renderer)
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        (void)io;
        ImGui::StyleColorsDark();
        ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
        ImGui_ImplSDLRenderer2_Init(renderer);
    }

    static void Shutdown()
    {
        ImGui_ImplSDLRenderer2_Shutdown();
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext();
    }

    static void BeginFrame()
    {
        ImGui_ImplSDL2_NewFrame();
        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui::NewFrame();
    }

    static void EndFrame()
    {
        ImGui::EndFrame();
    }

    static void Render()
    {
        ImGui::Render();
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
    }

    static void HandleEvent(SDL_Event* event)
    {
        ImGui_ImplSDL2_ProcessEvent(event);
    }
};

#endif // GUI_TOOLS_H
