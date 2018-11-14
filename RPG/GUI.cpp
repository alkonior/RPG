#include "pch.h"
#include "GUI.h"
using namespace RPG;
using namespace GUINSP;
using namespace ENGINE;
using TEXTURES::initCS;

GUI::GUI(Model& E):
	DataSource(E),
	shift(BaseShiftX,BaseShiftY), 
	WP(DataSource),
	MIP(DataSource),
	BP(DataSource){}

void GUI::init(size_t w, size_t h)
{
	_w = w;
	_h = h;
	initCS();
}

bool GUI::Comand(size_t)
{
	return false;
}

void GUI::Draw()
{
	
}

GUI::~GUI()
{
}
