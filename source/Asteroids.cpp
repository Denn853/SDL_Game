#include "Asteroids.h"

Asteroids::Asteroids(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl)
	: GameObject(renderer, 97, 91, Vector2(156, 0)) {

	position = pos;
	rotation = rot;
	scale = scl;

	velocity = Vector2();
	angularVelocity = 0.0f;

	acceleration = Vector2();
	angularAcceleration = 0.0f;

	linearDrag = 1.2f;
	angularDrag = 6.0f;

	accelerationFactor = 125.0f;					//Px/sec^2
	angularAccelerationFactor = 500.0f * 180.0f;	//Deg(graus)/sec^2
}

void Asteroids::UpdateMovement(float dt) {

	//MOVEMENT
	acceleration = Vector2();

		Vector2 dir;
		float rotationInRadians = rotation * (M_PI / 180.f); //Conversió de graus a radiants
		dir.x = cos(rotationInRadians);
		dir.y = sin(rotationInRadians);

		acceleration = dir * accelerationFactor;

	//ROTATION
	angularAcceleration = 0;

		//angularAcceleration = dt * angularAccelerationFactor; //Units: º/s
		//angularAcceleration = dt * -angularAccelerationFactor; //Units: º/s


	GameObject::UpdateMovement(dt);

}