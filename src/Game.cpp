#include "Game.h"

Game::Game(const char* title, int width, int height) : window(title, width, height) {}
Game::~Game() {}

void Game::run()
{
	while (window.isRunning())
	{
		handleEvents();
		handleInput();
		update();
		render();
	}
}

void Game::handleEvents() 
{
	window.handleEvents();
	InputManager::update();
}

void Game::handleInput()
{
	player.handleInput();
}

void Game::update()
{
	player.update();
}

void Game::render()
{
	window.clear();

	// Render Stuff here
	player.render(window.GetRenderer());

	window.display();
}