#include "Asteroid.h"

Asteroid::Asteroid(SDL_Renderer* rend)
	: GameObject(rend, 97, 91, Vector2(156, 0)) {

	// -------- CALCULATE RADIUS
	float spawnRadius = CalculateRadius(GAME_WIDTH, GAME_HEIGHT);

	// -------- CALCULATE POSITION IN SPHERE PERIMET ER WITH A GIVEN RADIUS (r)
	Vector2 perimeterPosition = CalculatePositionInRadius(spawnRadius);
	
	// -------- CLAMP TO RECTANGLE WITH WIDTH AND HEIGHT
	float halfHeight = (float)GAME_HEIGHT / 2.f + (float)radius;
	float halfWidth = (float)GAME_WIDTH / 2.f + (float)radius;

	perimeterPosition = ClampPositionToRectangle(perimeterPosition, halfWidth, halfHeight);


	// -------- TRANSFORM
	position = perimeterPosition;
	position = position + Vector2(halfWidth, halfHeight);
	rotation = rand() % 360;
	scale = Vector2(1.0f, 1.0f);

	// -------- PHYSICS
	acceleration = Vector2(0.0f, 0.0f);
	angularAcceleration = 0.0f;
	angularDrag = 0.0f;
	linearDrag = 0.0f;
	
	velocity = Vector2();
	angularVelocity = 0.0f;
}