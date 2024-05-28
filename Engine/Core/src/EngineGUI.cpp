#include "EngineGUI.h"

EngineGUI::EngineGUI() : m_window(nullptr), m_renderer(nullptr) {}

EngineGUI::~EngineGUI() {}

void EngineGUI::updateSelectedObject(Sprite *selectedSprite)
{
    if (selectedSprite)
    {
        // Aktualisiere die ausgewählten Objektinformationen basierend auf dem ausgewählten Sprite
        m_selectedObjectName = selectedSprite->getName();
        m_selectedObjectType = "Sprite"; // Hier kannst du den Typ des ausgewählten Objekts festlegen
        // Weitere Informationen aktualisieren...
    }
}

void EngineGUI::handleMouseClick(int mouseX, int mouseY, std::vector<Sprite *> &sprites)
{
    // Überprüfe, ob ein Sprite ausgewählt wurde
    for (Sprite *sprite : sprites)
    {
        if (sprite->isClicked(mouseX, mouseY))
        {
            // Ein Sprite wurde ausgewählt, aktualisiere die ausgewählten Objektinformationen
            updateSelectedObject(sprite);
            break;
        }
    }
}
void EngineGUI::handleImGuiEvents(SDL_Event &event)
{
    ImGui_ImplSDL2_ProcessEvent(&event);
}
void EngineGUI::initialize(SDL_Window *window, SDL_Renderer *renderer)
{
    m_window = window;
    m_renderer = renderer;
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;

    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer2_Init(renderer);

    ImGui::StyleColorsDark();
    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
}

void EngineGUI::newFrame()
{
    ImGui_ImplSDLRenderer2_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
}

void EngineGUI::render()
{
    ImGui::Render();
    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
}

void EngineGUI::shutdown()
{
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}

void EngineGUI::drawDetailsPanel()
{
    // Beginne ImGui-Docking
    // ImGui::DockSpaceOverViewport();

    // Beginne ein neues Fenster
    ImGui::Begin("Details", nullptr, ImGuiWindowFlags_NoCollapse);

    // Anzeigen des Namens des ausgewählten Objekts
    ImGui::Text("Name: %s", m_selectedObjectName.c_str());

    // Anzeigen des Typs des ausgewählten Objekts
    ImGui::Text("Type: %s", m_selectedObjectType.c_str());

    // Weitere Informationen hier hinzufügen...

    ImGui::End();
}

void EngineGUI::drawWindowController()
{
    ImGui::Begin("Window Controller");

    // Hier könntest du die hinzugefügten ImGui-Elemente rendern
    // Beispiel:
    ImGui::Text("Width: %d, Height: %d", wc_width, wc_height);
    ImGui::ColorPicker3("Background Color", (float *)&wc_color);
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

    getSize();

    ImGui::End();
}

void EngineGUI::getSize()
{
    wc_guiSize = ImGui::GetWindowSize();
    wc_width = static_cast<int>(wc_guiSize.x);
    wc_height = static_cast<int>(wc_guiSize.y);
}
int EngineGUI::getRColor()
{
    return (int)(wc_color.x * 255.0f);
}
int EngineGUI::getGColor()
{
    return (int)(wc_color.y * 255.0f);
}
int EngineGUI::getBColor()
{
    return (int)(wc_color.z * 255.0f);
}

void EngineGUI::setDebugMode(bool debugMode)
{
    isDebugMode = debugMode;
}