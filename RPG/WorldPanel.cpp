#include "pch.h"
#include "WorldPanel.h"
using std::vector;
using namespace RPG::TEXTURES;


RPG::GUINSP::WorldPanel::WorldPanel(WVC& W): 
Data(W),
Window(nullptr), Panel(nullptr),
w(0), h(0){}

void RPG::GUINSP::WorldPanel::init(Point lu, Point rd)
{
	w = rd.x - lu.x;
	h = rd.y - lu.y;
	Window = subwin(stdscr, h, w, lu.y, lu.x);
	while (!(Window))
	{
		Window = subwin(stdscr, --h, --w, lu.y, lu.x);
	}
	Panel = new_panel(Window);
	bottom_panel(Panel);
}

void RPG::GUINSP::WorldPanel::Draw()
{
	vector<vector<const Texture*>> in = Data.GetWorldInfo(w,h);
	auto res = wresize(Window, w, h) == ERR;
	for (size_t i = 0; i < h; i++)
	{
		for (size_t j = 0; j < w; j++)
		{
			in[i][j]->Draw(Point(i, j), Window);
		}
	}
	update_panels();
	doupdate();
	wrefresh(Window);
}

RPG::GUINSP::WorldPanel::~WorldPanel()
{
	if (Window) {
		del_panel(Panel);
		delwin(Window);
	}
}
