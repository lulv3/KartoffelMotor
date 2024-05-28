// TextureManager.cpp
#include "TextureManager.h"
#include <stdexcept>

TextureManager::TextureManager() : showTextureList(false) {}

TextureManager::~TextureManager()
{
    clear();
}

TextureManager &TextureManager::getInstance()
{
    static TextureManager instance;
    return instance;
}

SDL_Texture *TextureManager::loadTexture(SDL_Renderer *renderer, const std::string &filePath)
{
    SDL_Surface *surface = SDL_LoadBMP(filePath.c_str());
    if (!surface)
    {
        throw std::runtime_error("Failed to load texture: " + filePath + " - " + SDL_GetError());
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture)
    {
        SDL_FreeSurface(surface);
        throw std::runtime_error("Failed to create texture from surface: " + filePath + " - " + SDL_GetError());
    }

    SDL_FreeSurface(surface);
    textures[filePath] = texture;
    return texture;
}

void TextureManager::unloadTexture(const std::string &filePath)
{
    auto it = textures.find(filePath);
    if (it != textures.end())
    {
        SDL_DestroyTexture(it->second);
        textures.erase(it);
    }
}

void TextureManager::clear()
{
    for (auto &pair : textures)
    {
        SDL_DestroyTexture(pair.second);
    }
    textures.clear();
}

void TextureManager::showTextureListImGui()
{
    ImGui::Begin("Texture List", &showTextureList);
    for (const auto &pair : textures)
    {
        if (ImGui::Selectable(pair.first.c_str()))
        {
            currentTexturePath = pair.first;
        }
    }
    ImGui::End();
}
