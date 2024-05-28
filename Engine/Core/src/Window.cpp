#include "Window.h"

Window::Window(const char* title, int width, int height)
	: window(nullptr), renderer(nullptr), running(true) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
		running = false;
		return;
	}

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (!window) {
		std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
		running = false;
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
		running = false;
		return;
	}

}

Window::~Window() {
	destroy();
}

void Window::handleEvents()
{
	// ERROR: Cannot quit the game window.
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			running = false;
		}
	}
}

void Window::clear()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void Window::display()
{
	SDL_RenderPresent(renderer);
}

bool Window::isRunning() const
{
	return running;
}
SDL_Window* Window::GetWindow()
{
	return window;
}

SDL_Renderer* Window::GetRenderer()
{
	return renderer;
}