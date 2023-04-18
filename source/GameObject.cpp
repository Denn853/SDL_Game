#include "GameObject.h"

GameObject::GameObject(SDL_Renderer* renderer) {
	position = Vector2();
	rotation = 0.f;
	scale = Vector2(1.f, 1.f);

	//Load the texture
	SDL_Surface* surf = IMG_Load("resources/CatAttack.png");
	if (surf == nullptr) {
		std::cout << "Cannot load surface: " << SDL_GetError;
	}

	texture = SDL_CreateTextureFromSurface(renderer, surf);

	if (texture == nullptr) {
		std::cout << "Cannot load texture: " << SDL_GetError;
	}

	SDL_FreeSurface(surf);
};

void GameObject::Update(float dt) {

}

void GameObject::Render(SDL_Renderer* renderer) {
	SDL_Rect source{ 0, 0, 582/2, 639 };
	SDL_Rect destination{ 100, 100, source.w * scale.x, source.h * scale.y };
	//					   x	y	 w	  h
	SDL_RenderCopy(renderer, texture, &source, &destination);
}