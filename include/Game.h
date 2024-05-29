#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "Player.h"
#include "Input.h"
#include "Camera.h"
#include "Timer.h"
#include "gui_tools.h"

class Game
{
public:
	Game(const char* title, int width, int height);
	~Game();

	void run();

private:
	Window window;
	Player player;
	Camera camera;
	Timer timer;

	void update();
	void render();
	void handleEvents();
	void handleInput();
};

#endif // GAME_H