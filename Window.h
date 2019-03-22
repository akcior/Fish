#include"SDL.h"
#include"Fisherman.h"

class Window
{
	//int width, height;
	bool fullscr, running;
	SDL_Window* win;
	SDL_Renderer* ren;
	SDL_Event event;
	Fisherman *guardian;
	

public:
	int Init(int width, int height, bool fullscr);
	void Update();
	void Render();
	void HandleEvents();
	bool IsRunning();

	~Window();
};