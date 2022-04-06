#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Collision.h"

Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
auto& Player(manager.addEntity());
auto& Wall(manager.addEntity());

Game::Game()
{
	this->isRunning = false;
	this->window = nullptr;
	this->renderer = nullptr;
}

Game::~Game()
{
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		/*OutputDebugStringW(L"Iniazilizzazionne con successo");*/
		this->window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		/*if (this->window) OutputDebugStringW(L"Finestra creata");*/

		this->renderer = SDL_CreateRenderer(this->window, -1, 0);
		if (this->renderer)
		{
			/*OutputDebugStringW(L"render creato");*/
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
		
		this->isRunning = true;
	}
	else this->isRunning = false;

	map = new Map();
	
	//componenti ECS
	Player.addComponent<TransformComponent>(0,0,128,128,0.25f);
	Player.addComponent<KeyboardController>();
	Player.addComponent<SpriteComponent>("Assets/twitter1.png");
	Player.addComponent<ColliderComponent>("player");


	Wall.addComponent<TransformComponent>(300.0f, 300.0f, 32, 32*9, 1);
	Wall.addComponent<SpriteComponent>("Assets/wall.png");
	Player.addComponent<ColliderComponent>("wall");

}

void Game::handleEvents()
{
	SDL_PollEvent(&Game::event);
	switch (Game::event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	manager.refresh();
	manager.update();

	if (Collision::AABB(Player.getComponent<ColliderComponent>().collider,Wall.getComponent<ColliderComponent>().collider))
	{
		Wall.getComponent<SpriteComponent>().setTex("Assets/dirt.png");
	}
}

void Game::render()
{
	SDL_RenderClear(this->renderer);
	map->DrawMap();
	manager.draw();
	SDL_RenderPresent(this->renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
	SDL_Quit();

}

bool Game::running() { return this->isRunning; }
