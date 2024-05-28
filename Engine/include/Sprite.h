#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <string>
#include <iostream>

class Sprite
{
public:
    Sprite(int width, int height, int x, int y);
    ~Sprite();

    void loadImage(SDL_Renderer* renderer, const std::string &imagePath)
    {
        // Load texture
        SDL_Surface* surface = IMG_Load(imagePath.c_str());
        if (surface == nullptr)
        {
            // Handle error
            return;
        }
        m_texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        // Set source rect
        m_srcRect = { 0, 0, m_width, m_height };

        // Set destination rect
        m_dstRect = { 0, 0, m_width, m_height };
    }
    void render(SDL_Renderer *renderer, int x, int y);
    void setPosition(int x, int y);
    void setFlip(bool horizontal, bool vertical);
    void setRotation(float angle);
    void addAnimationFrame(const SDL_Rect &frameRect);
    void clearAnimationFrames();
    void setAnimationSpeed(int speed);
    void playAnimation(bool loop);
    void stopAnimation();
    void move(int dx, int dy);

    void setIsLocktInScreenSpace(bool value);
    int getWidth()
    {
        return m_width;
    }
    int getHeight()
    {
        return m_height;
    }

    bool isClicked(int mouseX, int mouseY);
    const SDL_Point &getPosition() const
    {
        return m_position;
    }
    const std::string &getName() const
    {
        return m_name;
    }
    bool isCollidingWith(const Sprite &other) const;

    void scaleSprite(int width, int height)
    {
        m_height = height;
		m_width = width;
    }

    void setDebugConsoleOutput(bool value)
    {
		debugConsoleOutput = value;
    }


private:
    std::string m_name;   // Name des Sprites
    SDL_Point m_position; // Die Position des Sprites
    SDL_Texture *m_texture;
    std::vector<SDL_Rect> m_animationFrames;
    SDL_Rect m_srcRect;
    SDL_Rect m_dstRect;
    int m_x, m_y;
    int m_width;
    int m_height;
    bool m_flipHorizontal, m_flipVertical;
    float m_rotation;
    int m_currentFrame;
    int m_animationSpeed;
    bool m_playingAnimation;
    bool m_loopAnimation;
    bool m_locktInScreenSpace;
    Uint32 m_lastFrameTime; // Definition für m_lastFrameTime hinzugefügt
    bool debugConsoleOutput = false;
};
