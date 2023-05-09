#pragma once

#include<SDL_image.h>
#include<iostream>

#include "UIObjects.h"

class UIImage : public UIObjects {
public:

	UIImage(SDL_Renderer* rend, Vector2 pos, float rot, Vector2 scl, std::string path, int w, int h, Vector2 pad)
		: UIObjects(rend, pos, rot, scl), resourcePath(path) {

		width = w;
		height = h;
		padding = pad;

		GenerateTexture(rend);
	}

	void Update(float dt) override {}
	void Render(SDL_Renderer* rend) override;

protected:
	void GenerateTexture(SDL_Renderer* rend) override;

	std::string resourcePath;
};