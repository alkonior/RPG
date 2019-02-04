#include "pch.h"
#include "Game.h"



Game::Game(json& config):_Gui(make_shared<GUI>(LINES,COLS)), _Controler(_Gui)
{
	start_color();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
    timeout(100);
    cbreak();
	_Gui->init(config);
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
			_Controler.Send(ch);
			flushinp();
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
