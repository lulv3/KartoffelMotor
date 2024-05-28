// TextureManager.h
#pragma once

#include <unordered_map>
#include <string>
#include <SDL.h>
#include "imgui.h"

class TextureManager
{
public:
    static TextureManager &getInstance();
    SDL_Texture *loadTexture(SDL_Renderer *renderer, const std::string &filePath);
    void unloadTexture(const std::string &filePath);
    void clear();
    void showTextureListImGui();

private:
    TextureManager();
    ~TextureManager();

    std::unordered_map<std::string, SDL_Texture *> textures;
    std::string currentTexturePath; // For ImGui
    bool showTextureList;           // For ImGui
};
