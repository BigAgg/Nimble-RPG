#include "Framework.h"

int main() {
	Framework* fw = new Framework();
	if (IsWindowReady()) {
		float delta;
		while (!WindowShouldClose()) {
			delta = GetFrameTime();
			fw->handleEvents();
			fw->handleInputs();
			fw->update(delta);
			fw->draw();
		}
	}
	delete fw;
	return 0;
}