#pragma once
#include "Game.h"

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	static SDL_Texture* LoadTexture(const char* filename);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
private:

};