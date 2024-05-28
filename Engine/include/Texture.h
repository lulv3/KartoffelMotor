// Texture.h

#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>
#include <string>
#include <memory>

class Texture
{
public:
    Texture(SDL_Texture *texture, int width, int height);
    ~Texture();

    int getWidth() const;
    int getHeight() const;
    SDL_Texture *getSDLTexture() const;
    void setColorMod(Uint8 r, Uint8 g, Uint8 b);
    void setBlendMode(SDL_BlendMode blending);
    void setAlpha(Uint8 alpha);

private:
    SDL_Texture *m_texture;
    int m_width;
    int m_height;
};

#endif // TEXTURE_H
