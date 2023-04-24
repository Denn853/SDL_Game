#include "Spaceship.h"

Spaceship::Spaceship(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl)
	: GameObject(renderer) {
	position = pos;
	rotation = rot;
	scale = scl;
}

void Spaceship::Update(float dt) {

}

void Spaceship::Render(SDL_Renderer* rend) {

	SDL_Rect source;
	source.x = 0;
	source.y = 0;
	source.w = 31;
	source.h = 39;

	SDL_Rect dest;
	dest.x = position.x - (int)((float)source.w * scale.x / 2.0f);
	dest.y = position.y - (int)((float)source.h * scale.y / 2.0f);
	dest.w = (float)source.w * scale.x;
	dest.h = (float)source.h * scale.x;

	SDL_RenderCopyEx(rend, texture,
					&source, &dest, 
					rotation, 
					NULL,				//Punt de rotació: NULL = center
					SDL_FLIP_NONE);		//Don't flip image
}