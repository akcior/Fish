#pragma once
#include "Fish.h"
#include<vector>
#include<time.h>
#include<SDL.h>

class Fisherman
{
	std::vector<Fish> fishes;
	double lastTime, presTime, deltaTime;
	vec borders;

public:
	Fisherman(vec borders);

	void CountTime();
	void AvoidWalls();
	void UpdateFish();
	void RenderFish(SDL_Renderer *ren);

	~Fisherman();

};
