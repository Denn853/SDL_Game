#include "GameplayScene.h"

void GameplayScene::Start(SDL_Renderer* rend) {
	Scene::Start(rend); //Parent function
	objects.push_back(new Spaceship(rend, Vector2(100.f, 100.f), 0.0f, Vector2(1.f, 1.f)));
	objects.push_back(new Asteroids(rend, Vector2(400.f + rand(), 400.f + rand()), 0.f + rand(), Vector2(1.f, 1.f)));
}
//Rand Formule
//value = min + rand() % (max - min + 1)

void GameplayScene::Update(float dt) {
	Scene::Update(dt);

	if (IM.GetKey(SDLK_SPACE, DOWN)) {
		/*finished = true;
		targetScene = "Main Menu";*/
		
		objects[0]->Destroy();
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