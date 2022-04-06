#pragma once
#include "Components.h"
#include "SDL.h"
#include "../TextureManager.h"

class SpriteComponent : public Component
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

	bool test = true;
	Uint32 Start = 0;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		setTex(path);
	}

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
	}

	void setTex(const char* path)
	{
		texture = TextureManager::LoadTexture(path);
	}

	void update() override
	{
		destRect.x = (int)transform->position.x;
		destRect.y = (int)transform->position.y;
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;

		
	/*	int diff = SDL_GetTicks() - Start;
		const int CK = 100;

		if (test && diff >= CK)
		{
			this->srcRect.x = 1;
			Start = SDL_GetTicks();
			test = !test;
		}
		else if (diff >= CK)
		{
			this->srcRect.x = 128;
			Start = SDL_GetTicks();
			test = !test;
		}*/
	}

	void draw() override
	{
		TextureManager::Draw(this->texture, this->srcRect, this->destRect);
	}

	~SpriteComponent()
	{
		SDL_DestroyTexture(texture);
	}
};
