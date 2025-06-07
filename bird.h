#pragma once
#include "config.h"
#include "scane.h"

class Bird {
private:
	Vector2 birdCoordinate{ 200,400 };

	Texture2D birdTexture{};

	int jumpY{};

	int height ;

	int width ;

	int gravitySpeed{};

	int jumpSpeed = 10;

	Rectangle bird = { birdCoordinate.x,birdCoordinate.y,float(width),float(height) };
public:

	Bird(Texture2D birdTexture, int jump) {
		this->birdTexture = birdTexture;

		jumpY = jump * 0.6;

		gravitySpeed = jumpY * 2.3;

		height = birdTexture.height;

		width = birdTexture.width;
	}
	// update bird rectangle
	void updateBird() {
		bird = { birdCoordinate.x,birdCoordinate.y,float(width),float(height) };
	}

	// reset bird position
	void reset() {
		// Reset position to starting position
		birdCoordinate = { 200, 400 };

		// Reset velocity/momentum
		gravitySpeed = jumpY * 2.3;

		// Update collision rectangle
		updateBird();
	}

	// update bird situation
	void update() {

		birdCoordinate.y += gravitySpeed * GetFrameTime();
		
		if (IsKeyPressed(KEY_SPACE)) {
			birdCoordinate.y -= jumpY;

		}
		if (collide()) {
			reset();
			scane.reset();
		}

		updateBird();

		render();
	}

	// draws bird
	void render() const {
		DrawTexture(birdTexture, int(birdCoordinate.x), int(birdCoordinate.y), WHITE);
	}
	
	// collision functions
	bool collide() {
		if (collideWall() || collidegroud()) {
			return true;
		}
		return false;
	}

	bool collideWall() const {
		//collision wall1
		if (CheckCollisionRecs(scane.wall1Bot(), bird)) {
			return true;
		}
		if (CheckCollisionRecs(scane.wall1Up(), bird)) {
			return true;
		}
		//collision wall2
		if (CheckCollisionRecs(scane.wall2Bot(), bird)) {
			return true;
		}
		if (CheckCollisionRecs(scane.wall2Up(), bird)) {
			return true;
		}
		//collision wall3
		if (CheckCollisionRecs(scane.wall3Bot(), bird)) {
			return true;
		}
		if (CheckCollisionRecs(scane.wall3Up(), bird)) {
			return true;
		}
		return false;
	}
	
	bool collidegroud() {
		if (bird.x + bird.height == screeny) {
			return true;
		}
		return false;
	}

};