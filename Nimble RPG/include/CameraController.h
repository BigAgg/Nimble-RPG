#pragma once

#include "raylib.h"

class CameraController : public Camera2D {
public:
	CameraController();
	~CameraController();

	void init(Vector2 target);
	void setTarget(Vector2 target);
	void setOffset();
	void zooming();
};