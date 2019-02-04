#include "pch.h"
#include "InfoPanel.h"


InfoPanel::InfoPanel(){}

void InfoPanel::init(Point lu, Point rd)
{
	w = rd.x-lu.x;
	h = rd.y-lu.y;
	Window = subwin(stdscr, h, w, lu.y, lu.x);
}

void InfoPanel::Draw(const WVC& Data)
{
	auto heroInfo = Data.getHeroInfo();
	wbkgdset(Window, COLOR_WHITE);
	wclear(Window);
	wmove(Window, 3, 1);
	wprintw(Window, "HP: %d / %d", heroInfo.Hp, heroInfo.MaxHp);
	wmove(Window, 7, 1);
	wprintw(Window, "MP: %d / %d", heroInfo.Mp, heroInfo.MaxMp);
	wrefresh(Window);

}
