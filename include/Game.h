#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "Player.h"

class Game
{
public:
	Game(const char* title, int width, int height);
	~Game();

	void run();

private:
	Window window;
	Player player;


	void update();
	void render();
	void handleEvents();
	void handleInput();
};

#endif // GAME_H