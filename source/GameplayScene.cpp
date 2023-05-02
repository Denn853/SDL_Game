#include "GameplayScene.h"

void GameplayScene::Start(SDL_Renderer* rend) {
	
	Scene::Start(rend); //Parent function
	spaceship = new Spaceship(rend, Vector2(100.f, 100.f), 0.0f, Vector2(1.f, 1.f));
	objects.push_back(spaceship);

	for (int i = 0; i < 10; i++)
	objects.push_back(new Asteroid(rend));
}
//Rand Formule
//value = min + rand() % (max - min + 1)

void GameplayScene::Update(float dt) {
	
	Scene::Update(dt);

	for (auto it = objects.begin(); it != objects.end(); it++) {
		// it = punter a object
		if (Asteroid* a = dynamic_cast<Asteroid*>(*it)) {
			// If asteroid collides with spaceship
				//Destroy asterois
				//Destroy spaceship
			Vector2 sToA = a->GetPosition() - spaceship->GetPosition();
			float distanceSquared = sToA.x * sToA.x + sToA.y * sToA.y;
			float squaredRadiusSum = 20 + 20;	//playerRadius + asteroidsRadius
			squaredRadiusSum *= squaredRadiusSum;

			if (distanceSquared < squaredRadiusSum) {
				spaceship->Destroy();
				a->Destroy();
			}
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