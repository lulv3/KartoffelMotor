// ParticleSystem.h

#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <vector>
#include <SDL.h>
#include "imgui.h"

struct Particle
{
    SDL_Rect rect;
    SDL_Color color;
    int lifetime; // Lifetime of the particle in frames
    int velocityX;
    int velocityY;
};

class ParticleSystem
{
public:
    ParticleSystem(int maxParticles);

    void emitParticle(int x, int y, int velocityX, int velocityY, const SDL_Color &color, int lifetime);

    void update();

    void render(SDL_Renderer *renderer);

    void renderImGui();

private:
    std::vector<Particle> m_particles;
    int m_maxParticles;
    int m_currentParticles; // Current number of active particles

    // ImGui variables
    bool m_showImGuiWindow;
};

#endif // PARTICLESYSTEM_H
