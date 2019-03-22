#include"SDL.h"
#include"Window.h"
#include<iostream>

int main(int argc, char *argv[])
{
	Window Game;
	Game.Init(600,600,false);
	while (Game.IsRunning())
	{
		Game.Update();
		Game.Render();
		Game.HandleEvents();
	}
	return 0;
}