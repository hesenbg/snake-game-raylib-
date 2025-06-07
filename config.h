#pragma once
#include "raylib.h"
#include <cstdlib>  
#include <ctime>

int screenx = 450;
int screeny = 450;

int fps= 60;
// walls

int wallWidth = 50;

float birdJump = 50;

bool isGameover = true;


int totalScore = 0;

// random
int random(int min,int max) {
	return  min + rand() % (max - min+1);
}

// scene 



