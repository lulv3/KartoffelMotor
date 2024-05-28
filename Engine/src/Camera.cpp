// Camera.cpp
#include "Camera.h"

Camera::Camera(int screenWidth, int screenHeight) : zoom(1.0f), offsetX(0), offsetY(0), showCameraSettings(false)
{
    viewport.x = 0;
    viewport.y = 0;
    viewport.w = screenWidth;
    viewport.h = screenHeight;
}

void Camera::update()
{
    // Implement camera update logic here (e.g., scrolling)
}

void Camera::setViewport(int x, int y, int width, int height)
{
    viewport.x = x;
    viewport.y = y;
    viewport.w = width;
    viewport.h = height;
}

void Camera::setZoom(float newZoom)
{
    zoom = newZoom;
}

void Camera::translate(int dx, int dy)
{
    offsetX += dx;
    offsetY += dy;
}

void Camera::centerOn(int x, int y)
{
    offsetX = x - viewport.w / 2;
    offsetY = y - viewport.h / 2;
}

void Camera::reset()
{
    offsetX = 0;
    offsetY = 0;
    zoom = 1.0f;
}

void Camera::setImGuiVisibility(bool visible)
{
    showCameraSettings = visible;
}

void Camera::showCameraSettingsImGui()
{
    if (showCameraSettings)
    {
        ImGui::Begin("Camera Settings", &showCameraSettings);
        ImGui::SliderFloat("Zoom", &zoom, 0.1f, 3.0f);
        ImGui::InputInt("Offset X", &offsetX);
        ImGui::InputInt("Offset Y", &offsetY);
        ImGui::End();
    }
}
