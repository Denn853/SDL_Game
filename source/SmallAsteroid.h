#pragma once

#include "Asteroid.h"

class SmallAsteroid : public Asteroid {
public:
	SmallAsteroid(SDL_Renderer* rend, Vector2 pos)
		: Asteroid(rend) {

		int random = rand() % 3;

		switch (random)
		{
		case 0:
			//GameObject(renderer, 19, 18, Vector2(128, 1))

			width = 19;
			height = 18;
			padding = Vector2(128.0f, 1.0f);
			break;

		case 1:
			//GameObject(renderer, 19, 21, Vector2(128, 22))

			width = 19;
			height = 21;
			padding = Vector2(128.0f, 22.0f);
			break;

		case 2:
			//GameObject(renderer, 21, 18, Vector2(166, 105))

			width = 21;
			height = 18;
			padding = Vector2(166.0f, 105.0f);
			break;
		}

		position = pos;
		velocity = CalculatePositionInRadius(100);
		angularVelocity = 100 - (rand() % 201); //Entre -100 i 100

		radius = CalculateRadius(width, height);

	}
};