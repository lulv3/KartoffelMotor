#include "Player.h"

Player::Player() : m_speed(180.0f), m_x(100), m_y(100), m_height(16), m_width(16), m_sprite(m_width, m_height, m_x, m_y) {}
Player::~Player() {}

void Player::init(SDL_Renderer* renderer)
{
	m_sprite.loadImage(renderer, "assets/img/Star_Red.png");
	std::cerr << "Player PosX: " << m_sprite.getPosition().x << ", PosY: " << m_sprite.getPosition().y << std::endl;
}
void Player::handleInput()
{
	if (InputManager::isKeyDown(SDLK_a)) {
		m_x -= m_speed;
	}
	if (InputManager::isKeyDown(SDLK_d)) {
		m_x += m_speed;
	}
}
void Player::update()
{
	std::cerr << "Player PosX: " << m_sprite.getPosition().x << ", PosY: " << m_sprite.getPosition().y << std::endl;
}
void Player::render(SDL_Renderer* renderer)
{
	m_sprite.render(renderer, m_x, m_y);
}