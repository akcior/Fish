#include"Fisherman.h"

Fisherman::Fisherman(vec borders)
{
	srand(time(NULL));
	vec pos, velo;

	for (int i = 0; i < 6; i++)
	{
		pos.x = rand() % 200;
		srand(time(NULL) + pos.x);
		pos.y = rand() % 200;
		velo.x = 20;
		velo.y = 20;
		fishes.push_back(Fish(pos, velo));
	}

	lastTime = SDL_GetTicks() * 0, 001;
	presTime = lastTime;
	this->borders = borders;
}

void Fisherman::CountTime()
{
	lastTime = presTime;
	presTime = SDL_GetTicks() * 0.001;
	deltaTime = presTime - lastTime;
}

void Fisherman::AvoidWalls()
{

}

void Fisherman::UpdateFish()
{
	for (Fish fish : fishes)
	{
		fish.UpdatePos(deltaTime);
		//printf("%f\n", fish.GetPos().x);
	}
}

void Fisherman::RenderFish(SDL_Renderer *ren)
{
	SDL_Rect rec;
	rec.w = 8;
	rec.h = 8;
	SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);

	for (Fish fish : fishes)
	{
		vec fishpos = fish.GetPos();
		rec.x = fishpos.x - rec.w / 2;
		rec.y = fishpos.y - rec.h / 2;
		SDL_RenderDrawRect(ren,&rec);
	}
}

Fisherman::~Fisherman()
{
	fishes.clear();
}