/* WINDOWCONTROLLER - TEST VERSION - 0.0.1*/
#include "WindowController.h"

WindowController::WindowController() : m_checkbox(false), m_slider(0.0f), guiSize(ImVec2(385, 445)), width(380), height(180) {}

WindowController::~WindowController() {}

void WindowController::Init(SDL_Window *window, SDL_Renderer *renderer)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;

    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer2_Init(renderer);

    ImGui::StyleColorsDark();
}

void WindowController::Shutdown()
{
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}

void WindowController::handleEvents(SDL_Event e)
{
    ImGui_ImplSDL2_ProcessEvent(&e);
}

void WindowController::render()
{
    if (isDebugMode)
    {
        ImGui::Begin("Window Controller");

        // Hier könntest du die hinzugefügten ImGui-Elemente rendern
        // Beispiel:
        ImGui::Text("Width: %d, Height: %d", width, height);
        ImGui::Checkbox("ImGui Sizable?", &m_checkbox);
        ImGui::ColorPicker3("Background Color", (float *)&color);
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        if (!m_checkbox)
        {
            ImGui::SetWindowSize(ImVec2(385, 445));
        }

        getSize();

        ImGui::End();
    }
}
void WindowController::getSize()
{
    guiSize = ImGui::GetWindowSize();
    width = static_cast<int>(guiSize.x);
    height = static_cast<int>(guiSize.y);
}
int WindowController::getRColor()
{
    return (int)(color.x * 255.0f);
}
int WindowController::getGColor()
{
    return (int)(color.y * 255.0f);
}
int WindowController::getBColor()
{
    return (int)(color.z * 255.0f);
}

void WindowController::setDebugMode(bool debugMode)
{
    isDebugMode = debugMode;
}