#include "pch.h"
#include "GUI.h"


GUI::GUI(Map& in):Engine(in)
{
	init_pair(0, COLOR_GREEN, COLOR_GREEN);
}

void GUI::Draw()
{
	
	const vector<vector<Texture>> const & map = Engine.GetInfo() ;
	for (size_t i = 0; i < map.size(); i++)
	{
		for (size_t j = 0; j < map[i].size(); j++)
		{
			attron(COLOR_PAIR(map[i][j].colorset));
			//attron(map[i][j].type);
			mvaddch(i,j,map[i][j].sym | 0x10000001);
			
			//attroff(COLOR_PAIR(map[i][j].colorset));
			attroff(map[i][j].type);
		}
	}
	refresh();
}

void GUI::Send(int)
{
}

GUI::~GUI()
{
}
