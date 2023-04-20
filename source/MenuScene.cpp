#include "MenuScene.h"

void MenuScene::Start(SDL_Renderer* rend) {
	Scene::Start(rend); //Parent function
}

void MenuScene::Update(float dt) {
	Scene::Update(dt);

	if (IM.GetKey(SDLK_1, DOWN)) {
		finished = true;
		targetScene = "Gameplay";
	}

	if (IM.GetKey(SDLK_2, DOWN)) {
		finished = true;
		targetScene = "Highscores";
	}
}

void MenuScene::Render(SDL_Renderer* rend) {
	Scene::Render(rend);

	std::cout << "Main Menu" << std::endl;
}

void MenuScene::Exit() {

}