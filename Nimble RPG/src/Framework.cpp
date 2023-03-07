#include "framework.h"

void debug(const char* msg, int posX, int posY) {
	DrawText(msg, posX, posY, 20, GREEN);
}

Framework::Framework() {
	loadSettings();
	init(WindowSettings.screenWidth, WindowSettings.screenHeight,
		WindowSettings.fullscreen, WindowSettings.vsync,
		WindowSettings.fps);
}
Framework::~Framework() {
	saveSettings();
	CloseWindow();
}

void Framework::init(uint32_t width, uint32_t height, bool fullscreen, bool vsync, uint32_t fps) {
	InitWindow(width, height, "Nimble RPG");
	SetTargetFPS(fps);
	if (fullscreen != IsWindowFullscreen()) {
		ToggleFullscreen();
	}
	if (vsync) {
		SetConfigFlags(FLAG_VSYNC_HINT);
	}
	WindowSettings.fps = fps;
	WindowSettings.fullscreen = fullscreen;
	WindowSettings.vsync = vsync;
	WindowSettings.screenHeight = height;
	WindowSettings.screenWidth = width;
}

void Framework::saveSettings() {
	using namespace std;
	namespace fs = filesystem;

	fs::create_directories("bin/");									// Creating directory

	ofstream file;													// Creating ofstream object
	file.open("bin/window.stg", ios::binary);						// Opening file in binary mode
	if (file.is_open() && file.good()) {							// Check if file is open and good
		file.write((char*)&WindowSettings, sizeof(WindowSettings));	// Write Settings struct to file
	}
};																	// returning true if file is saved and false if an error happened

void Framework::loadSettings() {
	using namespace std;
	ifstream file;													// Creating ifstream object
	file.open("bin/window.stg", ios::binary);						// Opening file in binary mode
	if (file.is_open() && file.good()) {							// Checking if file is open and good
		file.read((char*)&WindowSettings, sizeof(WindowSettings));	// Reading contents of file and writing it in Settings struct
	}
	else {
		WindowSettings.fps = 60;
		WindowSettings.fullscreen = false;
		WindowSettings.screenHeight = 1920;
		WindowSettings.screenWidth = 1080;
		WindowSettings.vsync = false;
	}
};

void Framework::handleEvents() {

}
void Framework::handleInputs() {

}
void Framework::update(float deltaTime) {

}
void Framework::draw() {
	Vector2 testVector2 = { 16.0f, 16.0f };
	camera.setOffset();
	camera.setTarget(testVector2);
	camera.zooming();
	camera.rotation = 0.0f;
	BeginDrawing();
		ClearBackground(GRAY);
		BeginMode2D(camera);
			DrawRectangle(0, 0, 32, 32, DARKGREEN);
		EndMode2D();
		debug("Test", 20, 30);
	EndDrawing();
}