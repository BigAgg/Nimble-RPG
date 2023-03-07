#pragma once

#include "raylib.h"
#include <vector>

class GameObject {
public:
	GameObject();
	~GameObject();

	virtual void input();
	virtual void update(float deltaTime);
	virtual void move(std::vector<GameObject*>* walls);
	virtual void draw();

private:
	struct {
		Vector2 position;
		Vector2 direction;
		bool isAlive = true;
		bool isRendered = true;
	}stats;
};