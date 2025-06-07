#include "config.h"
#include "bird.h"
#include "scane.h"
#include "button menu.h"
#include "string"
#include "animation.h"

int main() {
    
    InitWindow(screenx, screeny, "flappy bird");

    SetTargetFPS(fps); 
    // button variables
    int startButtonWidth = 160;
    int startButtonHeigth = 40;

    button startButton(screenx / 2-startButtonWidth/2, screeny/2-startButtonHeigth/2, startButtonHeigth,startButtonWidth);

    const char* text = "PLAY AGAIN";

    // mouse coordinates

    int mx{};
    int my{};

    Texture2D birdTexture = LoadTexture("textures/flappyBird.png");
    Bird bird(birdTexture, birdJump);
    
    std::srand(std::time(0));

    

    while (!WindowShouldClose()) {
        
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // updating game objects
        if (!isGameover) {
            bird.update();
            scane.update();   
        }

        if (bird.collide()) {
			isGameover = true;
        }

        //buttons & menu
        
		// mouse coordinates
        mx = GetMouseX();

        my = GetMouseY();

		if (isGameover) {
			startButton.drawButton();
            startButton.setText(text,20);
		}

        if (startButton.isPressed(mx, my)) {
            isGameover = false;
        }

        EndDrawing();
    }

    UnloadTexture(birdTexture);

    CloseWindow();
    return 0;
}

