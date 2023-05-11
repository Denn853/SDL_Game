#pragma once

#include "GameObject.h"
#include "InputManager.h"

class Spaceship : public GameObject {
public: 
	Spaceship(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl);

	bool ShootBullet();

protected:
	void Update(float dt) override;

private:

	void UpdateMovement(float dt) override;

	// -------- SHOOTING
	bool wantsToShoot;
	bool canShoot;

	float maxShotTime;
	float lastShotTime;

	void UpdateShot(float dt);
};