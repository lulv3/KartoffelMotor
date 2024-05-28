// TileMap.h

#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include <string>
#include <imgui.h>

class TileMap
{
public:
    TileMap();

    // Load a tile map from file
    bool loadMap(const std::string &filename);

    // Render the tile map
    void render();

    // Get tile at specific position
    int getTileAt(int x, int y) const;

    // Set tile at specific position
    void setTileAt(int x, int y, int tile);

private:
    std::vector<std::vector<int>> m_tiles;
    int m_tileWidth;
    int m_tileHeight;
};

#endif // TILEMAP_H
