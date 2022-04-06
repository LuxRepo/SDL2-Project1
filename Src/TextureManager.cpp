#include "TextureManager.h"

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

SDL_Texture* TextureManager::LoadTexture(const char* filename)
{
	SDL_Surface* TmpSurface = IMG_Load(filename);
	SDL_Texture*  playerTex = SDL_CreateTextureFromSurface(Game::renderer, TmpSurface);
	SDL_FreeSurface(TmpSurface);
	return playerTex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}
