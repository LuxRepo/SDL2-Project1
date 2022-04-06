//#include "GameObJ.h"
//#include "TextureManager.h"
//
//GameObJ::GameObJ(const char* texturesheet, int xpos, int ypos)
//{
//	this->objTexture = TextureManager::LoadTexture(texturesheet);
//	this->destRec = {0,0,0,0};
//	this->srcRect = {0,0,0,0};
//	this->xpos = xpos;
//	this->ypos = ypos;
//}
//
//void GameObJ::Render()
//{
//	SDL_RenderCopy(Game::renderer, this->objTexture, &this->srcRect, &this->destRec);
//}
//
//void GameObJ::Update()
//{
//	xpos++;
//	ypos++;
//
//	int diff = SDL_GetTicks()-Start;
//	const int CK = 100;
//
//	if (test && diff >= CK)
//	{
//		this->srcRect.x = 1;
//		Start = SDL_GetTicks();
//		test = !test;
//	}
//	else if(diff >= CK)
//	{
//		this->srcRect.x = 128;
//		Start = SDL_GetTicks();
//		test = !test;
//	}
//	
//
//	this->srcRect.h = 128;
//	this->srcRect.w = 128;
//
//	this->destRec.x = this->xpos;
//	this->destRec.y = this->ypos;
//	this->destRec.w = this->srcRect.w /2;
//	this->destRec.h = this->srcRect.h /2;
//}
