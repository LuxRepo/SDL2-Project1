#pragma once
#include <string>
#include "SDL.h"
#include "ECS.h"
#include "Components.h"

class ColliderComponent : public Component
{
public:
	ColliderComponent(std::string tag) { this->tag = tag;};
	~ColliderComponent(){};

	SDL_Rect collider;
	std::string tag;

	TransformComponent* transform;

	void init() override
	{
		if (!entity->hasComponents<TransformComponent>())
		{
			entity->addComponent<TransformComponent>();
		}
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override
	{
		collider.x = static_cast<int>(transform->position.x);
		collider.y = static_cast<int>(transform->position.y);
		collider.w = 32; //transform->width* transform->scale;
		collider.h = 32;/// transform->height* transform->scale;
	}
};