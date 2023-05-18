#include "Enemy.h"

Enemy::Enemy(SDL_Renderer* renderer, Vector2 pos)
	: GameObject(renderer, 53, 30, Vector2(196, 96)) {

	position = pos;

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

	maxShotTime = 0.5f;
	lastShotTime = maxShotTime;
}

void Enemy::Update(float dt) {
	GameObject::Update(dt);
	UpdateShot(dt);
}

void Enemy::UpdateMovement(float dt) {

	//MOVEMENT
	acceleration = Vector2();

		Vector2 dir;
		float rotationInRadians = rotation * (M_PI / 180.f); //Conversió de graus a radiants
		dir.x = cos(rotationInRadians);
		dir.y = sin(rotationInRadians);

		acceleration = dir * accelerationFactor;

	GameObject::UpdateMovement(dt);

}

bool Enemy::ShootBullet() {
	if (canShoot && wantsToShoot) {

		lastShotTime = 0.0f;

		return true;
	}
	return false;
}

void Enemy::UpdateShot(float dt) {

	// 1 - Update lastShotTime
	lastShotTime += dt;

	// 2 - canShoot
	canShoot = lastShotTime >= maxShotTime;

	// 3 - wantsToShoot
	wantsToShoot = IM.GetKey(SDLK_SPACE, KeyState::HOLD) || IM.GetKey(SDLK_SPACE, KeyState::DOWN);

}