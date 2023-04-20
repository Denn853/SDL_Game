#include "MenuScene.h"

void MenuScene::Start() {
	Scene::Start(); //Parent function
}

void MenuScene::Update(float dt) {
	Scene::Update(dt);

	if (IM.GetKey(SDLK_SPACE, DOWN)) {
		finished = true;
		targetScene = "Gameplay";
	}
}

void MenuScene::Render(SDL_Renderer* rend) {
	Scene::Render(rend);

	std::cout << "Main Menu" << std::endl;
}

void MenuScene::Exit() {

}