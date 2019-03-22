#include"Window.h"
#include<iostream>

int Window::Init(int width, int height, bool fullsrc)
{

	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		std::cout << "SDL_Init error";
		return 0;
	}
	if(fullsrc) SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_FULLSCREEN_DESKTOP, &win, &ren);
	else SDL_CreateWindowAndRenderer(width, height,0, &win, &ren);
	SDL_SetRenderDrawColor(ren,0,0,0,255);
	SDL_RenderClear(ren);
	SDL_RenderPresent(ren);

	int x, y;
	vec borders;
	SDL_GetWindowSize(win, &x, &y);
	borders.x = x;
	borders.y = y;
	guardian = new Fisherman(borders);

}
void Window::HandleEvents()
{
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE) running = 0;
			//else if(event.key.keysym.sym == SDLK_UP) 

		case SDL_QUIT:
			running = 0;
		}
	}
}

bool Window::IsRunning()
{
	return running;
}

void Window::Update()
{
	guardian->CountTime();
	guardian->AvoidWalls();
	guardian->UpdateFish();
}

void Window::Render()
{
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	SDL_RenderFillRect(ren, NULL);
	guardian->RenderFish(ren);
	SDL_RenderPresent(ren);
}

Window::~Window()
{
	delete(guardian);
}