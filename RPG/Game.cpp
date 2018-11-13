#include "pch.h"
#include "Game.h"


Game::Game(size_t seed):Engine(seed),Gui(Engine),Controler(Gui, Engine)
{
	initscr();
	start_color();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	Gui.init(stdscr->_maxx, stdscr->_maxy);
}

void Game::start()
{
	loop();
}

void Game::loop()
{

	while (true)
	{
		size_t ch = getch();

		if (ch != 27)
		{			
			Controler.Send(ch);
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
