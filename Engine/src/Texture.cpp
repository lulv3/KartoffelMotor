// Texture.cpp

#include "Texture.h"

Texture::Texture(SDL_Texture *texture, int width, int height)
    : m_texture(texture), m_width(width), m_height(height) {}

Texture::~Texture()
{
    if (m_texture != nullptr)
    {
        SDL_DestroyTexture(m_texture);
    }
}

int Texture::getWidth() const
{
    return m_width;
}

int Texture::getHeight() const
{
    return m_height;
}

SDL_Texture *Texture::getSDLTexture() const
{
    return m_texture;
}

void Texture::setColorMod(Uint8 r, Uint8 g, Uint8 b)
{
    SDL_SetTextureColorMod(m_texture, r, g, b);
}

void Texture::setBlendMode(SDL_BlendMode blending)
{
    SDL_SetTextureBlendMode(m_texture, blending);
}

void Texture::setAlpha(Uint8 alpha)
{
    SDL_SetTextureAlphaMod(m_texture, alpha);
}
