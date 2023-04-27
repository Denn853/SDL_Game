#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "Vector2.h"
#include "Utils.h"

class GameObject {
public:
	GameObject(SDL_Renderer* renderer, int w, int h, Vector2 pad);
	~GameObject();

	void virtual Update(float dt);
	void virtual Render(SDL_Renderer* renderer);

protected:

	Vector2 position;
	float rotation;
	Vector2 scale;

	SDL_Texture* texture;
	int width, height;
	Vector2 padding;

	void ClampPosition();
	virtual void UpdateMovement(float dt);

	Vector2 velocity;
	float angularVelocity;

	Vector2 acceleration;
	float angularAcceleration;

	float linearDrag;
	float angularDrag;

	float accelerationFactor;
	float angularAccelerationFactor;
};