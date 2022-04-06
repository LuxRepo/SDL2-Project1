#include "Map.h"
#include "TextureManager.h"

int lvl1[20][25] = 
{
	{0,1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

Map::Map()
{
	this->dirt = TextureManager::LoadTexture("Assets/dirt.png");
	this->grass = TextureManager::LoadTexture("Assets/grass.png");
	this->water = TextureManager::LoadTexture("Assets/water.png");

	LoadMap(lvl1);

	src.h = src.y = 0;
	dest.h = dest.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;
}

Map::~Map()
{
	SDL_DestroyTexture(dirt);
	SDL_DestroyTexture(grass);
	SDL_DestroyTexture(water);
}

void Map::LoadMap(int arr[20][25])
{
	for (size_t row = 0; row < 20; row++) for (size_t col = 0; col < 25; col++)this->map[row][col] = arr[row][col]; 
}

void Map::DrawMap()
{
	int type = 0;

	for (size_t row = 0; row < 20; row++) for (size_t col = 0; col < 25; col++)
	{
		type = this->map[row][col];

		dest.x = col * 32;
		dest.y = row * 32;

		switch (type)
		{
		case 0:
			TextureManager::Draw(this->water, src, dest);
			break;
		case 1:
			TextureManager::Draw(this->grass, src, dest);
			break;
		case 2:
			TextureManager::Draw(this->dirt, src, dest);
			break;
		default:
			break;
		}
	}
}
