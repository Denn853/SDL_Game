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

	float dt = 0.0f;
	float lastTime = (double)SDL_GetPerformanceCounter() / (double)SDL_GetPerformanceFrequency();
	
	const int FPS = 60;
	const float frameTime = 1.0f / (float)FPS;


	while (!IM.GetQuit()) {
		
		float currentTime = (double)SDL_GetPerformanceCounter() / (double)SDL_GetPerformanceFrequency();
		dt += currentTime - lastTime;
		lastTime = currentTime;

		if (dt > frameTime) {

			//UPDATE INPUT
			IM.Listen();

			//UPDATE LOGIC
			object.Update(dt);
			std::cout << dt << std::endl;

			//RENDER
			if (IM.GetKey(SDLK_SPACE, DOWN)) {
				SDL_SetRenderDrawColor(renderer, rand() % 255, rand() % 255, rand() % 255, 0xFF); //background color
			}
			//SDL_SetRenderDrawColor(renderer, 0xAA, 0x6f, 0xFF, 0xFF); //background color

			SDL_RenderClear(renderer);
			object.Render(renderer);
			SDL_RenderPresent(renderer);

			dt -= frameTime;
		}
	}
}

void GameEngine::Finish() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}