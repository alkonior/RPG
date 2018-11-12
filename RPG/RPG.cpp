// RPG.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "Game.h"

int main()
{
	initscr();
	start_color();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	Game game(stdscr->_maxx, stdscr->_maxy);
	game.start();
	return 0;
}
