// LevelEditorTool.h

#ifndef LEVELEDITORTOOL_H
#define LEVELEDITORTOOL_H

#include <vector>
#include <string>
#include <imgui.h>

class LevelEditorTool
{
public:
    LevelEditorTool();

    // Load a level from file
    bool loadLevel(const std::string &filename);

    // Save the current level to file
    bool saveLevel(const std::string &filename);

    // Add a new object to the level
    void addObject(const std::string &objectName, int x, int y);

    // Remove an object from the level
    void removeObject(int index);

    // Render the level editor tool interface
    void render();

private:
    std::vector<std::string> m_objects;
    std::vector<std::pair<int, int>> m_positions;
};

#endif // LEVELEDITORTOOL_H
