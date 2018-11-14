#include "pch.h"
#include "WorldPanel.h"
using std::vector;
using namespace RPG::TEXTURES;

RPG::GUINSP::WorldPanel::WorldPanel(WWC& W): 
Data(W),
Window(nullptr), Panel(nullptr),
w(0), h(0) {}

void RPG::GUINSP::WorldPanel::init(Point lu, Point rd)
{
	size_t i = rd.x - lu.x;
	i = rd.y - lu.y;
	Window = subwin(stdscr, rd.x - lu.x, rd.y - lu.y, lu.x, lu.y);
	Panel = new_panel(Window);
	bottom_panel(Panel);
	w = rd.x - lu.x;
	h = rd.y - lu.y;
}

void RPG::GUINSP::WorldPanel::Draw()
{
	vector<vector<const Texture*>> in = Data.GetWorldInfo(w,h);
	for (size_t i = 0; i < h; i++)
	{
		for (size_t j = 0; j < w; j++)
		{
			in[i][j]->Draw(Point(j, i), Window);
		}
	}
	update_panels();
	doupdate();
	touchwin(Window);
	wrefresh(Window);
}

RPG::GUINSP::WorldPanel::~WorldPanel()
{
	if (Window) {
		del_panel(Panel);
		delwin(Window);
	}
}
