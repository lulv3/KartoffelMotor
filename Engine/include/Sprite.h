#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <string>

class Sprite {
public:
    Sprite(SDL_Renderer* renderer, const std::string& filePath, int pixelSize = 16);
    ~Sprite();

    void Render();
    void SetPosition(int x, int y);
    void SetAlpha(Uint8 alpha);

    // Getters
    int GetWidth() const { return m_width; }
    int GetHeight() const { return m_height; }
    int GetX() const { return m_x; }
    int GetY() const { return m_y; }

private:
    SDL_Renderer* m_renderer;
    SDL_Texture* m_texture;
    int m_width; // in pixels
    int m_height; // in pixels
    int m_x; // in pixels
    int m_y; // in pixels

    SDL_Texture* LoadTexture(const std::string& filePath);
};

#endif // SPRITE_H
