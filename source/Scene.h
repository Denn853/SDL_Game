#pragma once
#include <vector>
#include <string>
#include <SDL.h>

#include "GameObject.h"
#include "InputManager.h"
#include "UIObjects.h"

class Scene {
public:
	Scene() = default;

	virtual void Start(SDL_Renderer* rend) {
		finished = false;
	}

	virtual void Update(float dt) {
		for (int i = objects.size() - 1; i >= 0; i--) {
			if (objects[i]->IsPendingDestroy()) {
				delete objects[i];
				objects.erase(objects.begin() + i);
			}
		}

		for (auto it = objects.begin(); it < objects.end(); it++) {
			(*it)->Update(dt);
		}
		for (auto it = uiObjects.begin(); it < uiObjects.end(); it++) {
			(*it)->Update(dt);
		}
	}

	virtual void Render(SDL_Renderer* rend) {
		for (auto it = objects.begin(); it < objects.end(); it++) {
			(*it)->Render(rend);
		}
		for (auto it = uiObjects.begin(); it < uiObjects.end(); it++) {
			(*it)->Render(rend);
		}
	}

	virtual void Exit() = 0;

	bool IsFinished() { return finished; }
	std::string GetTargetScene() { return targetScene; }

protected:
	std::vector<GameObject*> objects;
	std::vector<UIObjects*> uiObjects;

	bool finished = false;
	std::string targetScene;
};
