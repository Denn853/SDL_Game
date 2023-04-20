#include "GameplayScene.h"

void GameplayScene::Start() {
	Scene::Start(); //Parent function
}

void GameplayScene::Update(float dt) {
	Scene::Update(dt);

	if (IM.GetKey(SDLK_SPACE, DOWN)) {
		finished = true;
		targetScene = "Main Menu";
	}
}

void GameplayScene::Render(SDL_Renderer* rend) {
	Scene::Render(rend);

	std::cout << "Gameplay" << std::endl;
}

void GameplayScene::Exit() {

}