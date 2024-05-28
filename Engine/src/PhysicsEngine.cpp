// PhysicsEngine.cpp
#include "PhysicsEngine.h"

PhysicsEngine::PhysicsEngine() {}

void PhysicsEngine::addPhysicsObject(std::shared_ptr<PhysicsObject> object)
{
    m_objects.push_back(object);
}

void PhysicsEngine::removePhysicsObject(std::shared_ptr<PhysicsObject> object)
{
    auto it = std::find(m_objects.begin(), m_objects.end(), object);
    if (it != m_objects.end())
    {
        m_objects.erase(it);
    }
}

void PhysicsEngine::update()
{
    // Hier könnten Kollisionserkennungs- und physikalische Berechnungen erfolgen
    // Zum Beispiel: Kollisionsprüfung zwischen allen Objekten, Anwendung von Kräften usw.
}

void PhysicsEngine::drawImGuiWindow()
{
    ImGui::Begin("Physics Engine");

    ImGui::Text("Number of Physics Objects: %d", m_objects.size());

    if (ImGui::Button("Toggle ImGui Window"))
    {
        m_showImGuiWindow = !m_showImGuiWindow;
    }

    if (m_showImGuiWindow)
    {
        ImGui::Text("List of Physics Objects:");
        for (int i = 0; i < m_objects.size(); ++i)
        {
            ImGui::Text("Object %d", i);
            ImGui::Text("Collider: x=%d, y=%d, w=%d, h=%d",
                        m_objects[i]->getCollider().x,
                        m_objects[i]->getCollider().y,
                        m_objects[i]->getCollider().w,
                        m_objects[i]->getCollider().h);
            ImGui::Separator();
        }
    }

    ImGui::End();
}
