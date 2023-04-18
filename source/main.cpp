#include "GameEngine.h"
#include <stdlib.h>

int SDL_main(int argc, char* argv[]) {
	srand(time(NULL));

	GameEngine engine(500, 500);
	engine.Update();
	engine.Finish();

	return 0;
}