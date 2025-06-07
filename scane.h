#pragma once
#include "config.h"

class Wall {
private:
	// gap between up and bottom walls (y axis)
	int gapUpBottom=100;
	// left upper position of gap

	int wallx=screenx;

	int wally = 0;

	Vector2 gapPosition{ float(wallx),180 };
	//x y width height
	Rectangle upperWall = { float(wallx),0,float(wallWidth),gapPosition.y};
	Rectangle bottomWall={float(wallx),gapPosition.y+float(gapUpBottom),float(wallWidth),float(screeny-(gapPosition.y+gapUpBottom))};
public:
	Wall() {
		generate();
	}

	void updateWalls() {
		 upperWall = { float(wallx),0,float(wallWidth),gapPosition.y };
		 bottomWall = { float(wallx),gapPosition.y + float(gapUpBottom),float(wallWidth),float(screeny - (gapPosition.y + gapUpBottom)) };
	}

	//generates random values for the gap and position of walls
	void generate() { 

	    gapPosition.y=	random(150, screeny - 150);

		gapUpBottom = random(100, 130);

		updateWalls();
	}
	
	void drawRec() const {
		//upper wall
		DrawRectangleRec(upperWall, BLACK);
		
		//bottom wall
	    DrawRectangleRec(bottomWall, BLUE);
	}

	//moves wall around the window
	void moveWall() {
        wallx -= 50 * GetFrameTime();
		if (wallx <= 0) {
			wallx = screenx;
			generate();
		}
	}

	//updates the position and gaps of the walls
	void update() {

		updateWalls();

		moveWall();	  

		drawRec();
	}
	
	int getX() const {
		return wallx;
	}

	void setWallx(int x) {
		wallx = x;
	}

	Rectangle GetUpRec() const {
		return upperWall;
	}
	Rectangle GetBotRec() const {
		return bottomWall;
	}
};


class Scane {
private: 
	Wall wall1;
	Wall wall2;
	Wall wall3;

	bool isWall2Running=false;
	bool isWall3Running=false;

public:
	Scane() {
		// create 2 walls behind of the first wall( they will appear over time)
		wall1.setWallx(screenx);
		wall2.setWallx(screenx + screenx / 3);
		wall3.setWallx(screenx + 2 * screenx / 3);

		// generating random gaps and gap positions for each wall
		wall1.generate();
		wall2.generate();
		wall3.generate();
	}

	void reset() {
		// returning back all walls if player lose
		wall1.setWallx(screenx);
		wall2.setWallx(screenx + screenx / 3);
		wall3.setWallx(screenx + 2 * screenx / 3);

		// generating walls again
		wall1.generate();
		wall2.generate();
		wall3.generate();
	}

	void update() {
		// updating walls every time they hit the end of the window
		wall1.update();
		wall2.update();
		wall3.update();
	}

	// GETTER fucntions for walls. we use them in bird class for collide() function

	//wall1
	Rectangle wall1Up() {
		return wall1.GetUpRec();
	}
	Rectangle wall1Bot() {
		return wall1.GetBotRec();
	}
	//wall2
	Rectangle wall2Up() {
		return wall2.GetUpRec();
	}
	Rectangle wall2Bot() {
		return wall2.GetBotRec();
	}
	//wall3
	Rectangle wall3Up() {
		return wall3.GetUpRec();
	}
	Rectangle wall3Bot() {
		return wall3.GetBotRec();
	}
};
// deaclearing scane object
Scane scane;
