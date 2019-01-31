#include "pch.h"
#include "InfoPanel.h"


InfoPanel::InfoPanel(WVC& W):Data(W){}

void InfoPanel::init(Point lu, Point rd)
{
	w = rd.x-lu.x;
	h = rd.y-lu.y;
	Window = subwin(stdscr, h, w, lu.y, lu.x);
	while (!(Window))
	{
		Window = subwin(stdscr, --h, --w, lu.y, lu.x);
	}
	Panel = new_panel(Window);
	bottom_panel(Panel);
}

void InfoPanel::Draw()
{
	/*
	std::string  line1("HP:");
	std::string  line2("MP:");
	auto hero = Data.getHeroInfo();
	line1.push_back()
	*/
}
