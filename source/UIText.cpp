#include "UIText.h"

void UIText::Render(SDL_Renderer* rend) {

	SDL_Rect dest;
	dest.x = position.x - (int)((float)width * scale.x / 2.0f);
	dest.y = position.y - (int)((float)height * scale.y / 2.0f);
	dest.w = (float)width * scale.x;
	dest.h = (float)height * scale.x;

	SDL_RenderCopyEx(rend, texture,
		NULL, &dest,
		rotation,
		NULL,				//Punt de rotació: NULL = center
		SDL_FLIP_NONE);		//Don't flip image
}

void UIText::GenerateTexture(SDL_Renderer* rend) {

	int fontSize = 84;

	TTF_Font* font = TTF_OpenFont(fontPath.c_str(), fontSize);
	SDL_Color color{ 0x66, 0xFF, 0xFF, 0xFF };

	SDL_Surface* surf = TTF_RenderText_Solid(font, text.c_str(), color); //font, text, color
																		 //TTF_font, text, R-value
	if (surf == nullptr) {
		std::cout << "Something went wrong generating the text surface" << std::endl;
	}

	texture = SDL_CreateTextureFromSurface(rend, surf);

	width = surf->w;
	height = surf->h;

	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
}