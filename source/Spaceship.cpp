#include "Spaceship.h"

Spaceship::Spaceship(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl)
	: GameObject(renderer, 31, 39, Vector2(0, 0)) {
//	: GameObject(renderer, 40, 40, Vector2(40, 0)) {   -- ASTEROID

	position = pos;
	rotation = rot;
	scale = scl;

	velocity = Vector2();
	angularVelocity = 0.0f;

	acceleration = Vector2();
	angularAcceleration = 0.0f;

	linearDrag = 1.2f;
	angularDrag = 6.0f;

	accelerationFactor = 500.0f;			//Px/sec^2
	angularAccelerationFactor = 1000.0f * 180.0f;	//Deg(graus)/sec^2
}

void Spaceship::UpdateMovement(float dt) {

	//MOVEMENT
	acceleration = Vector2();

	if (IM.GetKey(SDLK_UP, DOWN) || IM.GetKey(SDLK_UP, HOLD)) {
		
		Vector2 dir;
		float rotationInRadians = rotation * (M_PI / 180.f); //Conversió de graus a radiants
		dir.x = cos(rotationInRadians);
		dir.y = sin(rotationInRadians);

		acceleration = dir * accelerationFactor;
	}

	//ROTATION
	angularAcceleration = 0;

	if (IM.GetKey(SDLK_RIGHT, DOWN) || IM.GetKey(SDLK_RIGHT, HOLD)) {
		angularAcceleration = dt * angularAccelerationFactor; //Units: º/s
	}
	if (IM.GetKey(SDLK_LEFT, DOWN) || IM.GetKey(SDLK_LEFT, HOLD)) {
		angularAcceleration = dt * -angularAccelerationFactor; //Units: º/s
	}

	GameObject::UpdateMovement(dt);

}