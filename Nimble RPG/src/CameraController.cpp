#include "CameraController.h"

CameraController::CameraController() {

}
CameraController::~CameraController() {

}

void CameraController::init(Vector2 target) {
	this->target = target;
}
void CameraController::setTarget(Vector2 target) {
	this->target = target;
}
void CameraController::setOffset() {
	float widthOffset = GetScreenWidth() / 2.0f;
	float heightOffset = GetScreenHeight() / 2.0f;
	Vector2 newOffset = { widthOffset, heightOffset };
	offset = newOffset;
}
void CameraController::zooming() {
	zoom += GetMouseWheelMove()*0.1f;
	if (zoom > 4.0f) {
		zoom = 4.0f;
	}
	else if (zoom < 1.0f) {
		zoom = 1.0f;
	}
}