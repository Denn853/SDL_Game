#include "MenuScene.h"

void MenuScene::Start(SDL_Renderer* rend) {
	Scene::Start(rend); //Parent function
	uiObjects.push_back(
		new UIImage(
			rend,
			Vector2(100, 100), 0.0f, Vector2(1, 1),
			"resources/CatAttack.png",
			582, 639, Vector2(0, 0)));
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