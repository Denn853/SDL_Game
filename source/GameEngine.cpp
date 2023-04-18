#include "GameEngine.h"

GameEngine::GameEngine(int windowWidth, int windowHeight) {
	InitSDL();
	InitWindowAndRenderer(windowWidth, windowHeight);
}

void GameEngine::InitSDL() {
	int result = SDL_Init(SDL_INIT_VIDEO);
	
	if (result < 0) {
		std::cout << "SDL_Init ERROR: " << SDL_GetError() << std::endl;
	}
}

void GameEngine::InitWindowAndRenderer(int windowWidth, int windowHeight) {
	window = SDL_CreateWindow("Susichi",			//Window name
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,	//Window position
		windowWidth, windowHeight,					//Window size
		SDL_WINDOW_SHOWN);							//Window will be shown by default

	if (window == nullptr) {
		std::cout << "ERROR creating window: " << SDL_GetError();
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == nullptr) {
		std::cout << "ERROR creating renderer: " << SDL_GetError();
	}
}

void GameEngine::Update() {
	GameObject object(renderer);
	bool quitGame = false;

	while (!quitGame) {
		//--------UPDATE INPUT
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT) {
				quitGame = true;
			}
		}

		//--------UPDATE LOGIC
		object.Update(0.f);

		//--------RENDER
		//Green 0x6F, 0xFF, 0xA6
		//Purple 0x6F, 0xFF, 0xA6
		SDL_SetRenderDrawColor(renderer, 0xAA, 0x6f, 0xFF, 0xFF); //background color
		//SDL_SetRenderDrawColor(renderer, rand() % 255, rand() % 255, rand() % 255, 0xFF); //background random color

		SDL_RenderClear(renderer);

		//--------RENDER OBJECTS
		//SDL_RenderCopyEx(...)
		object.Render(renderer);
		SDL_RenderPresent(renderer);
	}
}

void GameEngine::Finish() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}