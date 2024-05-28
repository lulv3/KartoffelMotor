#include "Player.h"

Player::Player(SDL_Renderer* renderer) : m_speed(0.1f), m_x(100), m_y(100), m_height(16), m_width(16), m_sprite(renderer, "assets/img/Star_Red.png", 32)
{

}
Player::~Player() {}

void Player::init(SDL_Renderer* renderer)
{
	std::cerr << "Player PosX: " << m_sprite.GetX() << ", PosY: " << m_sprite.GetY() << std::endl;
}

void Player::handleInput()
{
    if (Input::IsKeyDown(SDLK_d))
    {
        m_x += m_speed;
        m_sprite.SetPosition(m_x, m_y);
    }
	if (Input::IsKeyDown(SDLK_a))
	{
		m_x -= m_speed;
        m_sprite.SetPosition(m_x, m_y);
	}
}
void Player::handleEvents()
{
    /*
	switch (event.type) {
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_LEFT:
            m_x -= m_speed;
            break;
        case SDLK_RIGHT:
            m_x += m_speed;
            break;
        case SDLK_a:
            m_x -= m_speed;
            break;
        case SDLK_d:
            m_x += m_speed;
            break;
        default:
            break;
        }
}
	*/
}
void Player::update()
{
	
}
void Player::render(SDL_Renderer* renderer)
{
	m_sprite.Render();
}