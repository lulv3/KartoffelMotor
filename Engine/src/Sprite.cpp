#include "Sprite.h"

Sprite::Sprite(int width, int height, int x, int y)
    : m_texture(nullptr), m_x(x), m_y(y), m_width(width), m_height(height),
      m_flipHorizontal(false), m_flipVertical(false), m_rotation(0),
      m_currentFrame(0), m_animationSpeed(100), m_playingAnimation(false), m_loopAnimation(true), m_locktInScreenSpace(false) {}

Sprite::~Sprite()
{
    SDL_DestroyTexture(m_texture);
}

void Sprite::setIsLocktInScreenSpace(bool isLocktInScreenSpace)
{
    m_locktInScreenSpace = isLocktInScreenSpace;
}

void Sprite::render(SDL_Renderer *renderer, int x, int y)
{
    // Update destination rect position
    m_dstRect.x = x;
    m_dstRect.y = y;

    // Render sprite
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    if (m_flipHorizontal)
    {
        flip = (SDL_RendererFlip)(flip | SDL_FLIP_HORIZONTAL);
    }
    if (m_flipVertical)
    {
        flip = (SDL_RendererFlip)(flip | SDL_FLIP_VERTICAL);
    }
    SDL_RenderCopyEx(renderer, m_texture, &m_srcRect, &m_dstRect, m_rotation, NULL, flip);

    // Update animation frame if playing animation
    if (m_playingAnimation)
    {
        Uint32 currentTime = SDL_GetTicks();
        if (currentTime - m_lastFrameTime >= m_animationSpeed)
        {
            m_currentFrame = (m_currentFrame + 1) % m_animationFrames.size();
            m_lastFrameTime = currentTime;
            m_srcRect = m_animationFrames[m_currentFrame];
        }
    }
}
bool Sprite::isCollidingWith(const Sprite &other) const
{
    // Berechne die Grenzen der aktuellen Sprite
    int left = m_x;
    int right = m_x + m_width;
    int top = m_y;
    int bottom = m_y + m_height;

    // Berechne die Grenzen der anderen Sprite
    int otherLeft = other.m_x;
    int otherRight = other.m_x + other.m_width;
    int otherTop = other.m_y;
    int otherBottom = other.m_y + other.m_height;

    // Überprüfe, ob sich die Grenzen überschneiden
    bool collisionX = (right >= otherLeft) && (left <= otherRight);
    bool collisionY = (bottom >= otherTop) && (top <= otherBottom);

    // Rückgabe true, wenn es eine Überschneidung in beiden Achsen gibt, sonst false
    return collisionX && collisionY;
}

void Sprite::setPosition(int x, int y)
{
    m_x = x;
    m_y = y;
}
bool Sprite::isClicked(int mouseX, int mouseY)
{
    // Überprüfe, ob der Mausklick innerhalb der Begrenzungen des Sprites liegt
    return (mouseX >= m_x && mouseX <= m_x + m_width &&
            mouseY >= m_y && mouseY <= m_y + m_height);
}

void Sprite::setFlip(bool horizontal, bool vertical)
{
    m_flipHorizontal = horizontal;
    m_flipVertical = vertical;
}

void Sprite::setRotation(float angle)
{
    m_rotation = angle;
}

void Sprite::addAnimationFrame(const SDL_Rect &frameRect)
{
    m_animationFrames.push_back(frameRect);
}

void Sprite::clearAnimationFrames()
{
    m_animationFrames.clear();
}

void Sprite::setAnimationSpeed(int speed)
{
    m_animationSpeed = speed;
}

void Sprite::playAnimation(bool loop)
{
    m_loopAnimation = loop;
    m_playingAnimation = true;
}

void Sprite::stopAnimation()
{
    m_playingAnimation = false;
}

void Sprite::move(int dx, int dy)
{
    m_position.x += dx;
    m_position.y += dy;
}
