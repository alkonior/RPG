#include "pch.h"
#include "Game.h"


Game::Game(size_t width, size_t height):Engine(width,height), Gui(Engine, width, height)
{
}

void Game::start()
{
	loop();
}

void Game::loop()
{
	erase();
	Gui.Draw();
	while (true)
	{
		char ch = getch();
		if (ch != 'q')
		{			
			Gui.Send(ch);
			Gui.Draw();
		}
		else
		{
			break;
		}
	}

}

Game::~Game()
{
	endwin();
}
