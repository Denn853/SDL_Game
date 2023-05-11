#include "GameObject.h"

GameObject::GameObject(SDL_Renderer* renderer, int w, int h, Vector2 pad)
	: width(w), height(h), padding(pad)
{
	position = Vector2();
	rotation = 0.f;
	scale = Vector2(1.f, 1.f);

	radius = CalculateRadius(w, h);

	//Load the texture
	SDL_Surface* surf = IMG_Load("resources/asteroids_spritesheet.png");
	if (surf == nullptr) {
		std::cout << "Cannot load surface: " << SDL_GetError;
	}

	texture = SDL_CreateTextureFromSurface(renderer, surf);

	if (texture == nullptr) {
		std::cout << "Cannot load texture: " << SDL_GetError;
	}

	SDL_FreeSurface(surf);
};

GameObject::~GameObject() {
	SDL_DestroyTexture(texture);
}

void GameObject::Update(float dt) {
	UpdateMovement(dt);
	ClampPosition();
}

void GameObject::ClampPosition() {

	float scaleWidth = (float)width * scale.x;
	float scaleHeight = (float)height * scale.y;

	int biggestAxis = scaleWidth > scaleHeight ? scaleWidth : scaleHeight;

	//RIGHT
	if (position.x > GAME_WIDTH + biggestAxis) {
		position.x -= (GAME_WIDTH + biggestAxis * 2);
	}

	//LEFT
	if (position.x < 0.0f - biggestAxis) {
		position.x += (GAME_WIDTH + biggestAxis * 2);
	}

	//DOWN
	if (position.y > GAME_HEIGHT + biggestAxis) {
		position.y -= (GAME_HEIGHT + biggestAxis * 2);
	}

	//UP
	if (position.y < 0.0f - biggestAxis) {
		position.y += (GAME_HEIGHT + biggestAxis * 2);
	}
}

void GameObject::UpdateMovement(float dt) {

	//UPDATE VELOCITY AND ANGULAR_VELOCITY
	velocity = velocity + acceleration * dt;
	angularVelocity = angularVelocity + angularAcceleration * dt;

	//DRAG
	velocity = velocity * (1.0f - linearDrag * dt);
	angularVelocity = angularVelocity * (1.0f - angularDrag * dt);

	//UPDATE POSITION AND ROTATION
	position = position + (velocity * dt);   //Position = position + (velocity * time)
	rotation = rotation + (angularVelocity * dt);	//Rotation = rotation + (angularVelocity * time)
}

void GameObject::Render(SDL_Renderer* rend) {

	SDL_Rect source;
	source.x = padding.x;
	source.y = padding.y ;
	source.w = width;
	source.h = height;

	SDL_Rect dest;
	dest.x = position.x - (int)((float)source.w * scale.x / 2.0f);
	dest.y = position.y - (int)((float)source.h * scale.y / 2.0f);
	dest.w = (float)source.w * scale.x;
	dest.h = (float)source.h * scale.x;

	SDL_RenderCopyEx(rend, texture,
		&source, &dest,
		90.0f + rotation,
		NULL,				//Punt de rotació: NULL = center
		SDL_FLIP_NONE);		//Don't flip image
}
