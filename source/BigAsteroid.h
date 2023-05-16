#pragma once

 #include "Asteroid.h"

class BigAsteroid : public Asteroid {
public:
	BigAsteroid(SDL_Renderer* rend)
		: Asteroid(rend) {
		
		int random = rand() % 3;

		switch (random)
		{
		case 0:
			//GameObject(renderer, 73, 71, Vector2(0, 52))

			width = 73;
			height = 71;
			padding = Vector2 (0.0f, 52.0f);
			break;

		case 1:
			//GameObject(renderer, 73, 73, Vector2(78, 52))

			width = 73;
			height = 73;
			padding = Vector2(78.0f, 52.0f);
			break;

		case 2:
			//GameObject(renderer, 97, 91, Vector2(156, 0))

			width = 97;
			height = 91;
			padding = Vector2(156.0f, 0.0f);
			break;
		}

		velocity = CalculatePositionInRadius(40);
		angularVelocity = 40 - (rand() % 81); //Entre -40 i 40

		//radius = CalculateRadius(width, height);

	}
};