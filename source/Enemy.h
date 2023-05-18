#pragma once

#include "GameObject.h"
#include "InputManager.h"

class Enemy : public GameObject {
public:
	Enemy(SDL_Renderer* rend, Vector2 pos);
	//GameObject(renderer, 53, 30, Vector2(96, 196))

	bool ShootBullet();

	int GetScore() { return score; }

protected:
	void Update(float dt) override;

	int score;

private:

	void UpdateMovement(float dt) override;

	// -------- SHOOTING
	bool wantsToShoot;
	bool canShoot;

	float maxShotTime;
	float lastShotTime;

	void UpdateShot(float dt);
};