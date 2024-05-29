#include "Camera.h"

Camera::Camera(int screenWidth, int screenHeight)
    : m_screenWidth(screenWidth), m_screenHeight(screenHeight),
    m_worldWidth(0), m_worldHeight(0), m_targetX(0), m_targetY(0) {
    m_viewRect = { 0, 0, screenWidth, screenHeight };
}

void Camera::setTarget(float x, float y) {
    m_targetX = x - m_screenWidth / 2.0f;
    m_targetY = y - m_screenHeight / 2.0f;
}

void Camera::update() {
    m_viewRect.x = static_cast<int>(m_targetX);
    m_viewRect.y = static_cast<int>(m_targetY);

    if (m_viewRect.x < 0) m_viewRect.x = 0;
    if (m_viewRect.y < 0) m_viewRect.y = 0;
    if (m_viewRect.x + m_screenWidth > m_worldWidth) m_viewRect.x = m_worldWidth - m_screenWidth;
    if (m_viewRect.y + m_screenHeight > m_worldHeight) m_viewRect.y = m_worldHeight - m_screenHeight;
}

SDL_Rect Camera::getViewRect() const {
    return m_viewRect;
}

void Camera::setWorldSize(int width, int height) {
    m_worldWidth = width;
    m_worldHeight = height;
}

void Camera::setPosition(float x, float y) {
    m_targetX = x;
    m_targetY = y;
    if (m_targetX < 0) m_targetX = 0;
    if (m_targetY < 0) m_targetY = 0;
    if (m_targetX + m_screenWidth > m_worldWidth) m_targetX = m_worldWidth - m_screenWidth;
    if (m_targetY + m_screenHeight > m_worldHeight) m_targetY = m_worldHeight - m_screenHeight;
    update();
}
