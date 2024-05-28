#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"
#include "InputManager.h"

class Player
{
public:
	Player();
	~Player();

	void update();
	void handleInput();
	void render(SDL_Renderer* renderer);
	void init(SDL_Renderer* renderer);

private:
	Sprite m_sprite;

	float m_speed;
	float m_x, m_y;
	int m_height, m_width;

};

#endif // !PLAYER_H
