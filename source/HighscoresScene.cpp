#include "HighscoresScene.h"

void HighscoresScene::Start() {
	Scene::Start(); //Parent function
}

void HighscoresScene::Update(float dt) {
	Scene::Update(dt);

	if (IM.GetKey(SDLK_SPACE, DOWN)) {
		finished = true;
		targetScene = "Main Menu";
	}
}

void HighscoresScene::Render(SDL_Renderer* rend) {
	Scene::Render(rend);

	std::cout << "Highscores" << std::endl;
}

void HighscoresScene::Exit() {

}