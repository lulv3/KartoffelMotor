#include "Sprite.h"
#include <SDL_image.h>
#include <iostream>

Sprite::Sprite(SDL_Renderer* renderer, const std::string& filePath, int pixelSize)
    : m_renderer(renderer), m_texture(nullptr), m_width(pixelSize), m_height(pixelSize),
    m_x(0), m_y(0) {
    m_texture = LoadTexture(filePath);
    if (!m_texture) {
        std::cerr << "Failed to load texture: " << filePath << std::endl;
    }
}

Sprite::~Sprite() {
    if (m_texture) {
        SDL_DestroyTexture(m_texture);
    }
}

void Sprite::Render() {
    SDL_Rect destRect = { m_x, m_y, m_width, m_height };
    SDL_RenderCopy(m_renderer, m_texture, nullptr, &destRect);
}

void Sprite::SetPosition(int x, int y) {
    m_x = x;
    m_y = y;
}

void Sprite::SetAlpha(Uint8 alpha) {
    SDL_SetTextureAlphaMod(m_texture, alpha);
}

SDL_Texture* Sprite::LoadTexture(const std::string& filePath) {
    SDL_Surface* surface = IMG_Load(filePath.c_str());
    if (!surface) {
        std::cerr << "Unable to load image from " << filePath << ": " << IMG_GetError() << std::endl;
        return nullptr;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, surface);
    if (!texture) {
        std::cerr << "Unable to create texture from surface: " << SDL_GetError() << std::endl;
    }
    SDL_FreeSurface(surface);
    return texture;
}
