#include "pch.h"
#include "GUI.h"
#define FLOOR 1
GUI::GUI(Map& in):Engine(in)
{
	
}

void GUI::Draw()
{
	erase();
	init_pair(FLOOR, COLOR_BLACK, COLOR_WHITE);
	const vector<vector<Texture>> const & map = Engine.GetInfo() ;
	for (size_t i = 0; i < map.size(); i++)
	{
		for (size_t j = 0; j < map[i].size(); j++)
		{
			attron(COLOR_PAIR(map[i][j].colorset));
			mvaddch(i,j,map[i][j].sym);
			attroff(COLOR_PAIR(map[i][j].colorset));	
		}
	}
	refresh();
}

void GUI::Send(int in)
{
	Engine.Comand(in);
}

GUI::~GUI()
{
}
