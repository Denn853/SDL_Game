#pragma once

#include "Asteroid.h"

class MediumAsteroid : public Asteroid {
public:
	MediumAsteroid(SDL_Renderer* rend, Vector2 pos)
		: Asteroid(rend) {

		int random = rand() % 2;

		switch (random)
		{
		case 0:
			//GameObject(renderer, 39, 36, Vector2(41, 3))

			width = 39;
			height = 36;
			padding = Vector2(41.0f, 3.0f);
			break;

		case 1:
			//GameObject(renderer, 42, 38, Vector2(82, 2))

			width = 42;
			height = 38;
			padding = Vector2(82.0f, 2.0f);
			break;
		}

		position = pos;
		velocity = CalculatePositionInRadius(70);
		angularVelocity = 70 - (rand() % 141); //Entre -70 i 70

		radius = CalculateRadius(width, height);

	}
};