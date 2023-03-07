#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>

#include <raylib.h>
#include "GameObject.h"
#include "CameraController.h"

class Framework {
public:
	Framework();
	~Framework();

	void init(uint32_t width, uint32_t height, bool fullscreen, bool vsync, uint32_t fps);

	void loadSettings();
	void saveSettings();

	void handleEvents();
	void handleInputs();
	void update(float deltaTime);
	void draw();

	struct {
		uint32_t screenWidth = 1920;
		uint32_t screenHeight = 1080;
		uint32_t fps = 60;
		bool fullscreen = false;
		bool vsync = false;
	}WindowSettings;

	CameraController camera;

	Rectangle clippingRect;
	Music music;
};