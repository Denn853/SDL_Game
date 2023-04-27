#include "Spaceship.h"

Spaceship::Spaceship(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl)
	: GameObject(renderer, 31, 39) {
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