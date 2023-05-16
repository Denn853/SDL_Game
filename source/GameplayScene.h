#pragma once

#include "Scene.h"
#include "Spaceship.h"
#include "BigAsteroid.h"
#include "MediumAsteroid.h"
#include "SmallAsteroid.h"
#include "Bullet.h"

enum GameplayState { ALIVE, DEAD };

class GameplayScene : public Scene {
public:
	GameplayScene()
		: Scene() {}

	void Start(SDL_Renderer* rend) override;
	void Update(float dt) override;

private:
	Spaceship* spaceship;
	SDL_Renderer* renderer; //Required for spawning

	GameplayState currentState;
	int lives;
	float currentStateTime;
	const float stateTimeThreshold = 3.0f;

	void DesctroySpaceship();
	void RespawnSpaceship();
};