#ifndef CAMERA_H
#define CAMERA_H

#include <SDL.h>

class Camera {
public:
    Camera(int screenWidth, int screenHeight);

    void setTarget(float x, float y);
    void update();

    SDL_Rect getViewRect() const;

    void setWorldSize(int width, int height);
    void setPosition(float x, float y);

private:
    int m_screenWidth, m_screenHeight;
    int m_worldWidth, m_worldHeight;
    SDL_Rect m_viewRect;
    float m_targetX, m_targetY;
};

#endif // CAMERA_H
