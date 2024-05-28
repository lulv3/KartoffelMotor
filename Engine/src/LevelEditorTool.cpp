// LevelEditorTool.cpp

#include "LevelEditorTool.h"
#include "imgui.h"

LevelEditorTool::LevelEditorTool()
{
    // Initialize
}

bool LevelEditorTool::loadLevel(const std::string &filename)
{
    // Load level from file
    return true; // Placeholder
}

bool LevelEditorTool::saveLevel(const std::string &filename)
{
    // Save level to file
    return true; // Placeholder
}

void LevelEditorTool::addObject(const std::string &objectName, int x, int y)
{
    // Add object to level
    m_objects.push_back(objectName);
    m_positions.emplace_back(x, y);
}

void LevelEditorTool::removeObject(int index)
{
    // Remove object from level
    if (index >= 0 && index < m_objects.size())
    {
        m_objects.erase(m_objects.begin() + index);
        m_positions.erase(m_positions.begin() + index);
    }
}

void LevelEditorTool::render()
{
    // Render the level editor interface using ImGui
    ImGui::Begin("Level Editor");

    // Display objects and positions
    for (size_t i = 0; i < m_objects.size(); ++i)
    {
        ImGui::Text("Object %d: %s - Position: (%d, %d)", i, m_objects[i].c_str(), m_positions[i].first, m_positions[i].second);
        ImGui::SameLine();
        if (ImGui::Button(("Remove##" + std::to_string(i)).c_str()))
        {
            removeObject(i);
        }
    }

    ImGui::End();
}
