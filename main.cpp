#include "raylib.h"
#include <cstdlib>

int main() {
	InitWindow(150, 150, "A Press Counter");
	SetWindowState(FLAG_VSYNC_HINT);
    	SetWindowIcon(LoadImage("resources/swaggin.png"));

	int screenHeight = GetScreenHeight();
	int screenWidth = GetScreenWidth();

	int jumps = -1;

	while (!WindowShouldClose()) {
		if (IsKeyPressed(KEY_SPACE)) {
			jumps++;
		}

		if (IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) {
			jumps++;
		}

		if (IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) {
			jumps = -1;
		}

       	 	if (IsKeyPressed(KEY_BACKSPACE)) {
			jumps = -1;
		}

		BeginDrawing();
			ClearBackground(MAGENTA);
			int textwidth = MeasureText(TextFormat("%i", jumps), 50);
			DrawText(TextFormat("%i", jumps), 55, 50, 60, WHITE);
		EndDrawing();
	}

	CloseWindow();
}
