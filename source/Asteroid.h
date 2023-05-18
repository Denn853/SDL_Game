#pragma once

#include "GameObject.h"
#include "InputManager.h"

class Asteroid : public GameObject {
public:
	Asteroid(SDL_Renderer* rend);
	int GetScore() { return score; }

protected: 
	int score;

};

	//GameObject BigAsteroids[3];
	//GameObject(renderer, 97, 91, Vector2(156, 0))
	//GameObject(renderer, 73, 71, Vector2(0, 52))
	//GameObject(renderer, 73, 73, Vector2(78, 52))

	//GameObject MediumAsteroids[2];
	//GameObject(renderer, 39, 36, Vector2(41, 3))
	//GameObject(renderer, 42, 38, Vector2(82, 2))

	//GameObject SmallAsteroids[3];
	//GameObject(renderer, 19, 18, Vector2(128, 1))
	//GameObject(renderer, 19, 21, Vector2(128, 22))
	//GameObject(renderer, 21, 18, Vector2(166, 105))