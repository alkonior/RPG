#include "pch.h"
#include "Game.h"

using namespace RPG;
using namespace ENGINE;
using namespace GUINSP;

Game::Game(json& config):Engine(config), Gui(Engine), Controler(Gui, Engine)
{
	initscr();
	start_color();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	int my= LINES, mx= COLS;
	Gui.init(mx, my);
}

void Game::start()
{
	loop();
}

void Game::loop()
{
	Gui.Draw();
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
