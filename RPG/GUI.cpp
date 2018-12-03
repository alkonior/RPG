#include "pch.h"
#include "GUI.h"
using namespace RPG;
using namespace GUINSP;
using namespace ENGINE;
using TEXTURES::initCS;

GUI::GUI(Model& E):
	DataSource(E),
	WP(DataSource),
	MIP(DataSource),
	BP(DataSource){}

void GUI::init(size_t w, size_t h)
{
	_w = w;
	_h = h;
	_lu_shift=Point(BaseLeftShiftX, BaseUpShiftY),
	_rd_shift=Point(stdscr->_maxx - BaseRightShiftX, stdscr->_maxy - BaseDownShiftY),
	initCS();
	refresh();
	WP.init(_lu_shift, _rd_shift);
}

bool GUI::Comand(size_t)
{
	return false;
}

void GUI::Draw()
{
	WP.Draw();
	mvaddch(_w-1, _h-1, '1');
}

GUI::~GUI()
{
}
