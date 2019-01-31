#include "pch.h"
#include "Game.h"



Game::Game(json& config):_Engine(config), _Gui(_Engine), _Controler(_Gui, _Engine)
{
	initscr();
	start_color();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);

    timeout(100);

	int my= LINES, mx= COLS;
	_Gui.init(mx, my);
}

void Game::start()
{
	loop();
}

void Game::loop()
{
	_Gui.Draw();
	while (true)
	{
		size_t ch = getch();

		if (ch != 27)
		{			
			_Controler.Send(ch);
			_Gui.Draw();
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
