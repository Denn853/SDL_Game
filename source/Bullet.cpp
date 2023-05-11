#include "Bullet.h"

Bullet::Bullet(SDL_Renderer* rend, Vector2 position, float angle, float velocityFactor)
	: GameObject(rend, 7, 8, Vector2(33, 31)) {

	this->position = position;

	float radAngle = angle * (M_PI / 180.0f);

	velocity = Vector2(cos(radAngle), sin(radAngle)) * velocityFactor;
	angularVelocity = 0.0f;

	acceleration = Vector2();
	angularAcceleration = 0.0f;

	linearDrag = 0.0f;
	angularDrag = 0.0f;

	accelerationFactor = 0.0f;
	angularAccelerationFactor = 0.0f;

	lifetime = 1.0f; // in seconds
}

void Bullet::Update(float dt) {

	GameObject::Update(dt);

	UpdateLifetime(dt);
}

void Bullet::UpdateLifetime(float dt) {

	lifetime -= dt;
	if (lifetime <= 0.0f) {
		Destroy();
	}
}