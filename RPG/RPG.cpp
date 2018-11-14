// RPG.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "Game.h"

using namespace RPG;
using namespace TEXTURES;
/*
int main()
{
	Game game(1);
	game.start();
	return 0;
}
*/


void init_wins(WINDOW **wins, int n);

int main()
{
	WINDOW *my_wins[3];
	PANEL  *my_panels[3];
	PANEL  *top;
	int ch;
	int i;

	/* инициализация ncurses */
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	/* инициализация цветовой палитры */
	if (!has_colors())
	{
		endwin();
		printf("\nОшибка! Не поддерживаются цвета\n");
		return 1;
	}
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLUE);
	init_pair(2, COLOR_GREEN, COLOR_RED);
	init_pair(3, COLOR_BLUE, COLOR_GREEN);

	// инициализируются окна
	init_wins(my_wins, 3);

	// создание панелей на основе созданных окон
	my_panels[0] = new_panel(my_wins[0]);
	my_panels[1] = new_panel(my_wins[1]);
	my_panels[2] = new_panel(my_wins[2]);

	// устанавливаем указатели на следующее окно
	// для перехода при нажатии Tab на следующее окно
	set_panel_userptr(my_panels[0], my_panels[1]);
	set_panel_userptr(my_panels[1], my_panels[2]);
	set_panel_userptr(my_panels[2], my_panels[0]);

	// обновление и прорисовка
	update_panels();
	mvprintw(0, 0, "Tab - следующая панель F1 - Выход");
	doupdate();

	// т.к. панель с индексом 2 создавалась последней 
	// значит она и будет верхней
	top = my_panels[2];

	// цикл обработки сообщений с клавиатуры
	while ((ch = getch()) != KEY_F(1))
	{
		switch (ch)
		{
		case '\t': // переход на следующую панель
			top = (PANEL *)panel_userptr(top);
			top_panel(top);
			break;
		}

	// обновление и перерисовка
		update_panels();
		doupdate();
	}

	// уничтожение созданных панелей и окон
	for (i = 0; i < 3; ++i)
	{
		del_panel(my_panels[i]);
		delwin(my_wins[i]);
	}

	//завершение программы
	endwin();
	return 0;
}

// инициализируются окна
void init_wins(WINDOW **wins, int n)
{
	int x, y, i;

	y = 2;
	x = 10;

	for (i = 0; i < n; ++i)
	{
		wins[i] = newwin(10, 70, y, x);
		wbkgdset(wins[i], COLOR_PAIR(i + 1));
		wclear(wins[i]);
		wrefresh(wins[i]);

		y += 3;
		x += 7;
	}
}