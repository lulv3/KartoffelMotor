#include "Game.h"

Game::Game(const char* title, int width, int height) : window(title, width, height), player(window.GetRenderer()) {}
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
	Input::Update();
	
	window.handleEvents();
	player.handleEvents();
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