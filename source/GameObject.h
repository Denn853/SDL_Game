#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "Vector2.h"

class GameObject {
public:
	GameObject(SDL_Renderer* renderer);
	~GameObject();

	void virtual Update(float dt);
	void virtual Render(SDL_Renderer* renderer);

protected:
	Vector2 position;
	float rotation;
	Vector2 scale;

	SDL_Texture* texture;
};