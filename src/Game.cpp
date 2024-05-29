#include "Game.h"

Game::Game(const char* title, int width, int height) : window(title, width, height), player(window.GetRenderer()), camera(800, 600), timer()
{
	camera.setWorldSize(2000, 2000);
	GuiTools::Init(window.GetWindow(), window.GetRenderer());
}

Game::~Game() { GuiTools::Shutdown(); }

void Game::run()
{
	while (window.isRunning())
	{
		timer.update(); // Update timer at the beginning of each game loop
		handleEvents();
		update();
		render();
	}
}

void Game::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		Input::Update(event);
		Input::SetDeltaTime(timer.getDeltaTime());
		GuiTools::HandleEvent(&event);
		window.handleEvents(&event);
		player.handleEvents(&event);

		// example how to use the `Input` class
		// if(Input::IsKeyDown(SDLK_ESCAPE)) { window.setRunning(false); }


	}
}


void Game::update()
{
	player.handleInput();
	player.update();
	camera.setTarget(player.getX(), player.getY());
	camera.update();
}

void Game::render()
{
	window.clear();

	SDL_Rect viewRect = camera.getViewRect();
	SDL_RenderSetViewport(window.GetRenderer(), &viewRect);

	player.render(window.GetRenderer());

#pragma region Render ImGui
	GuiTools::BeginFrame();
	ImGui::Begin("Hello, world!");
	ImGui::Text("Hello, world!");
	ImGui::End();
	GuiTools::EndFrame();

	GuiTools::Render();
#pragma endregion


	window.display();
}
