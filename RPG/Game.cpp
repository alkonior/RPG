#include "pch.h"
#include "Game.h"


Game::Game(size_t width, size_t height):Engine(width,height), Gui(Engine)
{
}

void Game::start()
{
	initscr();
	start_color();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	loop();
}

void Game::loop()
{
	erase();
	Gui.Draw();
	while (true)
	{
		int ch = getch();
		if (ch != 'q')
		{
			erase();
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
