#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"
#include "Input.h"
#include <iostream>

class Player
{
public:
	Player(SDL_Renderer* renderer);
	~Player();

	void update();
	void handleInput();
	void handleEvents(SDL_Event* event);
	void render(SDL_Renderer* renderer);
	void init();

	int getX() { return m_x; }
	int getY() { return m_y; }

private:
	Sprite m_sprite;

	float m_speed;
	float m_x, m_y;
	int m_height, m_width;

};

#endif // !PLAYER_H
