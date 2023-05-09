#include "MenuScene.h"

void MenuScene::Start(SDL_Renderer* rend) {
	Scene::Start(rend); //Parent function
	uiObjects.push_back(
		new UIImage(
			rend,
			Vector2(100, 100), 0.0f, Vector2(0.3, 0.3), //pos, rot, scale
			"resources/CatAttack.png",
			582, 639, Vector2(0, 0)));

	uiObjects.push_back(
		new UIText(
			rend,
			Vector2(250, 250), 0.0f, Vector2(1.f, 1.f),
			"Vaporeon",
			"resources/Hyperspace.ttf"));
}

void MenuScene::Update(float dt) {
	Scene::Update(dt);

	if (UIText* txt = dynamic_cast<UIText*>(uiObjects[1])) {
		txt->ChangeText(std::to_string(dt));
	}

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