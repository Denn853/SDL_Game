#include "GameplayScene.h"

void GameplayScene::Start(SDL_Renderer* rend) {
	
	Scene::Start(rend); //Parent function

	renderer = rend;

	spaceship = new Spaceship(rend, Vector2(100.f, 100.f), 0.0f, Vector2(1.f, 1.f));
	objects.push_back(spaceship);

	for (int i = 0; i < 10; i++) {
		objects.push_back(new Asteroid(rend));
	}
}
//Rand Formule
//value = min + rand() % (max - min + 1)

void GameplayScene::Update(float dt) {
	
	Scene::Update(dt);

	for (auto it = objects.begin(); it != objects.end(); it++) {
		// it = punter a object
		if (Asteroid* a = dynamic_cast<Asteroid*>(*it)) {

			// -------- COLLISION WITH SPACESHIP
			if (spaceship != nullptr) {
				// If asteroid collides with spaceship
					//Destroy asterois
					//Destroy spaceship
				bool colliding = CheckCollision(
					spaceship->GetPosition(), spaceship->GetRadius() * 0.5f,
					a->GetPosition(), a->GetRadius() * 0.5f
				);

				if(colliding) {
					spaceship->Destroy();
					spaceship = nullptr;
					//finished = true;
					//targetScene = "Main Menu";
					a->Destroy();
				}
			}

			// -------- COLLISION WITH BULLETS
			for (auto it2 = objects.begin(); it2 != objects.end() && !a->IsPendingDestroy(); it2++) {
				if (Bullet* b = dynamic_cast<Bullet*>(*it2)) {

				}
			}
		}
	}

	if (spaceship != nullptr) {
		if (spaceship->ShootBullet()) {
			objects.push_back(new Bullet(renderer, spaceship->GetPosition(), spaceship->GetRotation(), 300.0f));
		}
	}
}

void GameplayScene::Render(SDL_Renderer* rend) {
	Scene::Render(rend);

	std::cout << "Gameplay" << std::endl;
}

void GameplayScene::Exit() {
	for (auto it = objects.begin(); it != objects.end(); it++) {
		delete(*it);
	}
	objects.clear();
}