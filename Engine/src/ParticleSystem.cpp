// ParticleSystem.cpp

#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(int maxParticles) : m_maxParticles(maxParticles), m_currentParticles(0), m_showImGuiWindow(true) {}

void ParticleSystem::emitParticle(int x, int y, int velocityX, int velocityY, const SDL_Color &color, int lifetime)
{
    if (m_currentParticles < m_maxParticles)
    {
        Particle particle;
        particle.rect.x = x;
        particle.rect.y = y;
        particle.rect.w = 5; // Example particle width
        particle.rect.h = 5; // Example particle height
        particle.velocityX = velocityX;
        particle.velocityY = velocityY;
        particle.color = color;
        particle.lifetime = lifetime;
        m_particles.push_back(particle);
        ++m_currentParticles;
    }
}

void ParticleSystem::update()
{
    for (int i = 0; i < m_particles.size(); ++i)
    {
        m_particles[i].rect.x += m_particles[i].velocityX;
        m_particles[i].rect.y += m_particles[i].velocityY;
        --m_particles[i].lifetime;
        if (m_particles[i].lifetime <= 0)
        {
            m_particles.erase(m_particles.begin() + i);
            --m_currentParticles;
        }
    }
}

void ParticleSystem::render(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    for (const auto &particle : m_particles)
    {
        SDL_SetRenderDrawColor(renderer, particle.color.r, particle.color.g, particle.color.b, particle.color.a);
        SDL_RenderFillRect(renderer, &particle.rect);
    }
}

void ParticleSystem::renderImGui()
{
    if (m_showImGuiWindow)
    {
        ImGui::Begin("Particle System");
        ImGui::Text("Current particles: %d", m_currentParticles);
        ImGui::Checkbox("Show Particle System", &m_showImGuiWindow);
        ImGui::End();
    }
}
