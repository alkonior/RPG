#include "pch.h"
#include "WorldPanel.h"


WorldPanel::WorldPanel(): 
Window(nullptr),
w(0), h(0){}

void WorldPanel::init(Point lu, Point rd)
{
	w = rd.x - lu.x;
	h = rd.y - lu.y;
	Window = subwin(stdscr, h, w, lu.y, lu.x);
	while (!(Window))
	{
		Window = subwin(stdscr, --h, --w, lu.y, lu.x);
	}
}

void WorldPanel::Draw(const WVC& Data) const
{
	vector<vector<const Texture*>> in = Data.GetMapInfo(w,h);
	auto res = wresize(Window, w, h) == ERR;
	for (size_t i = 0; i<h; i++)
	{
		for (size_t j = 0; j<w; j++)
		{
			in[i][j]->Draw(Point(i, j), Window);
		}
	}
	doupdate();
	wrefresh(Window);
}

WorldPanel::~WorldPanel()
{
	if (Window) {
		delwin(Window);
	}
}
