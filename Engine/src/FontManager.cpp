// FontManager.cpp

#include "FontManager.h"

FontManager::FontManager()
{
    if (TTF_Init() == -1)
    {
        // Handle initialization error
    }
}

FontManager::~FontManager()
{
    for (auto &pair : m_fonts)
    {
        TTF_CloseFont(pair.second);
    }
    TTF_Quit();
}

bool FontManager::loadFont(const std::string &filePath, const std::string &fontName, int fontSize)
{
    TTF_Font *font = TTF_OpenFont(filePath.c_str(), fontSize);
    if (font == nullptr)
    {
        // Handle font loading error
        return false;
    }
    m_fonts[fontName] = font;
    return true;
}

TTF_Font *FontManager::getFont(const std::string &fontName)
{
    auto it = m_fonts.find(fontName);
    if (it != m_fonts.end())
    {
        return it->second;
    }
    return nullptr;
}

void FontManager::drawText(SDL_Renderer *renderer, const std::string &fontName, const std::string &text, int x, int y, SDL_Color color)
{
    TTF_Font *font = getFont(fontName);
    if (font == nullptr)
    {
        // Handle font not found error
        return;
    }
    SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if (surface == nullptr)
    {
        // Handle rendering error
        return;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr)
    {
        // Handle texture creation error
        SDL_FreeSurface(surface);
        return;
    }
    SDL_Rect dstRect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}
