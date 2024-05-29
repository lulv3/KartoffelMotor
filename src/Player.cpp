#include "Player.h"
#include "Input.h" // Vergewissern Sie sich, dass Input.h eingebunden ist, um auf Eingaben zuzugreifen

Player::Player(SDL_Renderer* renderer) :
    m_speed(100.0f),
    m_x(100),
    m_y(100),
    m_height(16),
    m_width(16),
    m_sprite(renderer, "assets/img/Star_Red.png", 32)
{
    // Initialisieren Sie hier alle notwendigen Parameter des Spielers
    init();
}

Player::~Player() {}

void Player::init()
{
    // Hier können Sie zusätzliche Initialisierungen vornehmen, falls erforderlich
    m_sprite.SetPosition(m_x, m_y);
}

void Player::handleInput()
{

}

void Player::handleEvents(SDL_Event* event)
{
    // Hier können Sie Ereignisse verarbeiten, falls erforderlich
    float deltaTime = Input::GetDeltaTime();

    // Bewegung des Spielers basierend auf der Eingabe und der Delta-Zeit aktualisieren
    if (Input::IsKeyDown(SDLK_d)) {
        m_x += m_speed;
        std::cerr << "X: " + std::to_string(m_x) + ", delta: " + std::to_string(deltaTime) << std::endl;
    }
    if (Input::IsKeyDown(SDLK_a)) {
        m_x -= m_speed;
    }

    // Aktualisieren Sie die Position des Sprites entsprechend der neuen Spielerposition
    m_sprite.SetPosition(m_x, m_y);
}

void Player::update()
{
    // Hier können Sie zusätzliche Aktualisierungen vornehmen, falls erforderlich
}

void Player::render(SDL_Renderer* renderer)
{
    // Rendern Sie den Spieler-Sprite
    m_sprite.Render();
}
