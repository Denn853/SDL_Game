#include "Spaceship.h"

Spaceship::Spaceship(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl)
	: GameObject(renderer) {
	position = pos;
	rotation = rot;
	scale = scl;

	velocity = Vector2();
	angularVelocity = 0.0f;

	acceleration = Vector2();
	angularAcceleration = 0.0f;

	linearDrag = 0.05f;
	angularDrag = 0.1f;

	accelerationFactor = 600.0f;			//Px/sec^2
	angularAccelerationFactor = 140000.0f;	//Deg(graus)/sec^2
}

void Spaceship::Update(float dt) {
	UpdateMovement(dt);
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
	velocity = velocity * (1.0f - linearDrag);
	angularVelocity = angularVelocity * (1.0f - angularDrag);

	//UPDATE POSITION AND ROTATION
	position = position + (velocity * dt);   //Position = position + (velocity * time)
	rotation = rotation + (angularVelocity * dt);	//Rotation = rotation + (angularVelocity * time)
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
					90.0f + rotation, 
					NULL,				//Punt de rotació: NULL = center
					SDL_FLIP_NONE);		//Don't flip image
}