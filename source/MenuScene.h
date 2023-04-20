#pragma once

#include "Scene.h"
#include "InputManager.h"

class MenuScene : public Scene {
public:
	MenuScene()
		: Scene() {}

	void Start() override;

	void Update(float dt) override;
	void Render(SDL_Renderer* rend) override;

	void Exit() override;

};