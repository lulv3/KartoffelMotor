// PhysicsEngine.h
#pragma once

#include <vector>
#include <memory>
#include "SDL.h"
#include "imgui.h"

class PhysicsObject
{
public:
    PhysicsObject(SDL_Rect collider) : m_collider(collider) {}

    SDL_Rect getCollider() const { return m_collider; }

protected:
    SDL_Rect m_collider;
};

class PhysicsEngine
{
public:
    PhysicsEngine();

    void addPhysicsObject(std::shared_ptr<PhysicsObject> object);
    void removePhysicsObject(std::shared_ptr<PhysicsObject> object);

    void update();

    // ImGui Interface
    void drawImGuiWindow();

private:
    std::vector<std::shared_ptr<PhysicsObject>> m_objects;

    // ImGui variables
    bool m_showImGuiWindow = false;
};
