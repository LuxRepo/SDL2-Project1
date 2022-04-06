#include "Game.h"
#include <Windows.h>
#include <string>

int WINAPI WinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	bool limitFPS = true;
	const int FPS = 120;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime = 1;

	Game* game = new Game();
	game->init("Titolo",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,640, false);

	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;
		if ((frameDelay > frameTime)&& limitFPS)SDL_Delay(frameDelay - frameTime);
	}

	game->clean();

	return 0;
}

