#include "Spaceship.h"

Spaceship::Spaceship(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl)
	: GameObject(renderer, 31, 39, Vector2(0, 0)) {

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

	wantsToShoot = false;
	canShoot = false;

	maxShotTime = 1.0f;
	lastShotTime = maxShotTime;
}

void Spaceship::Update(float dt) {
	GameObject::Update(dt);
	UpdateShot(dt);
}

void Spaceship::UpdateMovement(float dt) {

	//MOVEMENT
	acceleration = Vector2();

	if (IM.GetKey(SDLK_UP, DOWN) || IM.GetKey(SDLK_UP, HOLD)) {
		
		Vector2 dir;
		float rotationInRadians = rotation * (M_PI / 180.f); //Conversi� de graus a radiants
		dir.x = cos(rotationInRadians);
		dir.y = sin(rotationInRadians);

		acceleration = dir * accelerationFactor;
	}

	//ROTATION
	angularAcceleration = 0;

	if (IM.GetKey(SDLK_RIGHT, DOWN) || IM.GetKey(SDLK_RIGHT, HOLD)) {
		angularAcceleration = dt * angularAccelerationFactor; //Units: �/s
	}
	if (IM.GetKey(SDLK_LEFT, DOWN) || IM.GetKey(SDLK_LEFT, HOLD)) {
		angularAcceleration = dt * -angularAccelerationFactor; //Units: �/s
	}

	GameObject::UpdateMovement(dt);

}

bool Spaceship::ShootBullet() {
	if (canShoot && wantsToShoot) {

		lastShotTime = 0.0f;

		return true;
	}
	return false;
}

void Spaceship::UpdateShot(float dt) {

	// 1 - Update lastShotTime
	lastShotTime += dt;

	// 2 - canShoot
	canShoot = lastShotTime >= maxShotTime;

	// 3 - wantsToShoot
	wantsToShoot = IM.GetKey(SDLK_SPACE, KeyState::HOLD) || IM.GetKey(SDLK_SPACE, KeyState::DOWN);

}