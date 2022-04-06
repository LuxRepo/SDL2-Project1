#pragma once
#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component
{
public:
	Vector2D position;
	Vector2D velocity;

	int height;
	int width;
	float scale;

	int speed = 3;

	TransformComponent()
	{
		position.x = 0.0f;
		position.y = 0.0f;
		height = 32;
		width = 32;
		scale = 1;

	}

	TransformComponent(float sc)
	{
		position.x = 0.0f;
		position.y = 0.0f;
		height = 32;
		width = 32;
		scale = sc;

	}

	TransformComponent(float x, float y)
	{
		position.x = x;
		position.y = y;
		height = 32;
		width = 32;
		scale = 1;
	}

	TransformComponent(float x, float y, int w, int h, float sc)
	{
		position.x = x;
		position.y = y;
		height = h;
		width = w;
		scale = sc;
	}
	void init() override
	{
		velocity.x = 0;
		velocity.y = 0;
	}

	void update() override
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}

};