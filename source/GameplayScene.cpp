#include "GameplayScene.h"

void GameplayScene::Start(SDL_Renderer* rend) {
	
	currentState = GameplayState::ALIVE;
	currentStateTime = 0.0f;
	lives = 3;
	
	Scene::Start(rend); //Parent function
	renderer = rend;

	RespawnSpaceship();
	int asteroidsSpawn = 10;
	for (int i = 0; i < asteroidsSpawn; i++) {
		objects.push_back(new BigAsteroid(rend));
	}

	RespawnEnemy();

}
//Rand Formule
//value = min + rand() % (max - min + 1)

void GameplayScene::Update(float dt) {
	
	currentStateTime += dt;

	int objectsSize = objects.size();
	for (int i = 0; i < objectsSize; i++) {
		if (BigAsteroid* big = dynamic_cast<BigAsteroid*>(objects[i])) {
			if (big->IsPendingDestroy()) {
				objects.push_back(new MediumAsteroid(renderer, big->GetPosition()));
				objects.push_back(new MediumAsteroid(renderer, big->GetPosition()));
			}
		}

		if (MediumAsteroid* big = dynamic_cast<MediumAsteroid*>(objects[i])) {
			if (big->IsPendingDestroy()) {
				objects.push_back(new SmallAsteroid(renderer, big->GetPosition()));
				objects.push_back(new SmallAsteroid(renderer, big->GetPosition()));
			}
		}
	}

	Scene::Update(dt);

	int asteroidsLeft = 0;

	// -------- COLLISIONS
	for (auto it = objects.begin(); it != objects.end(); it++) {
		// it = punter a object
		if (Asteroid* a = dynamic_cast<Asteroid*>(*it)) {
			asteroidsLeft++;
			
			// -------- COLLISION WITH SPACESHIP
			if (spaceship != nullptr && currentStateTime > stateTimeThreshold) {
				// If asteroid collides with spaceship
					//Destroy asterois
					//Destroy spaceship
				bool colliding = CheckCollision(
					spaceship->GetPosition(), spaceship->GetRadius() * 0.5f,
					a->GetPosition(), a->GetRadius() * 0.5f
				);

				if(colliding) {
					DesctroySpaceship();
					a->Destroy();
				}
			}

			// -------- COLLISION WITH BULLETS
			for (auto it2 = objects.begin(); it2 != objects.end() && !a->IsPendingDestroy(); it2++) {
				if (Bullet* b = dynamic_cast<Bullet*>(*it2)) {
					bool colliging = CheckCollision(
						b->GetPosition(), b->GetRadius(),
						a->GetPosition(), a->GetRadius() * 0.5f
					);

					if (colliging) {
						a->Destroy();
						b->Destroy();
					}
				}
			}
		}
	}


	if (spaceship != nullptr) {
		if (spaceship->ShootBullet()) {
			Vector2 offset = Vector2(
				cos(spaceship->GetRotation() * M_PI / 180.f), 
				sin(spaceship->GetRotation() * M_PI / 180.f)
			) * spaceship->GetRadius();
			
			objects.push_back(new Bullet(renderer, spaceship->GetPosition() + offset, spaceship->GetRotation() , 300.0f));
		}
	}

	if (currentState == GameplayState::DEAD && currentStateTime > stateTimeThreshold) {
		if (lives != 0) {
			RespawnSpaceship();
		}
		else {
			finished = true;
			targetScene = "Main Menu";
		}
	}

	if (asteroidsLeft == 0) {
		for (int i = 0; i < 10; i++) {
			objects.push_back(new BigAsteroid(renderer));
		}
	}
}

void GameplayScene::RespawnSpaceship() {
	spaceship = new Spaceship(renderer, Vector2(GAME_WIDTH / 2, GAME_HEIGHT / 2), 0.0f, Vector2(1.f, 1.f));
	objects.push_back(spaceship);

	currentState = GameplayState::ALIVE;
	currentStateTime = 0.0f;
}

void GameplayScene::DesctroySpaceship() {
	spaceship->Destroy();
	spaceship = nullptr;

	currentState = GameplayState::DEAD;
	currentStateTime = 0.0f;

	lives--;
}

void GameplayScene::RespawnEnemy() {
	enemy = new Enemy(renderer, Vector2(GAME_WIDTH / 2, GAME_HEIGHT / 2));
	objects.push_back(enemy);

	currentState = GameplayState::ALIVE;
	currentStateTime = 0.0f;
}

void GameplayScene::DesctroyEnemy() {
	enemy->Destroy();
	enemy = nullptr;

	currentState = GameplayState::DEAD;
	currentStateTime = 0.0f;

	lives--;
}

