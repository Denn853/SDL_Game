#pragma once

#include "GameObject.h"

class Bullet : public GameObject {
public:
	Bullet(SDL_Renderer* rend, Vector2 position, float angle, float velocityFactor);

	void Update(float dt) override;

protected:
	float lifetime;

	void UpdateLifetime(float dt);
};