#pragma once

#include "Scene.h"
#include "UIImage.h"
#include "UIText.h"

class MenuScene : public Scene {
public:
	MenuScene()
		: Scene() {}

	void Start(SDL_Renderer* rend) override;
	void Update(float dt) override;
};