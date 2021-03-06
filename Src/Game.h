#pragma once
#ifndef GAME_H
#define GAME_H
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_image.h"

class Game
{
public: 
	Game();
	~Game();
	
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running();

	static SDL_Renderer* renderer;
	static SDL_Event event;
private:
	int count = 0;
	bool isRunning;
	SDL_Window* window;
};





#endif // !GAME_H





