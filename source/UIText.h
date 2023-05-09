#pragma once
#include "SDL_ttf.h"
#include "iostream"

#include "UIObjects.h"

class UIText : public UIObjects {
public:

	UIText(SDL_Renderer* rend, Vector2 pos, float rot, Vector2 scl, std::string txt, std::string path)
		:UIObjects(rend, pos, rot, scl), text(txt), fontPath(path), rend(rend) {
		GenerateTexture(rend);
	}

	void Update(float dt) override {}
	void Render(SDL_Renderer* rend) override;

	void ChangeText(std::string newText) { 
		SDL_DestroyTexture(texture);
		text = newText;
		GenerateTexture(rend);
	}

protected:
	
	void GenerateTexture(SDL_Renderer* rend) override;
	
	std::string text;
	std::string fontPath;

	SDL_Renderer* rend;
};

