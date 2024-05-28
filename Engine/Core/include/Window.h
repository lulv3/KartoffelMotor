#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <iostream>

class Window
{
public:
	Window(const char* title, int width, int height);
	~Window();

	void handleEvents();
	void clear();
	void display();

	bool isRunning() const;

	SDL_Renderer* GetRenderer();
	SDL_Window* GetWindow();
	void destroy()
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}


private:
	SDL_Renderer* renderer;
	SDL_Window* window;

	int windowWidth;
	int windowHeight;	
	const char* windowTitle;
	bool running;
};

#endif // WINDOW_H