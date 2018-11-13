#include "pch.h"
#include "GUI.h"

GUI::GUI(Model& E):Engine(E),shift(BaseShiftX,BaseShiftY){}

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
	Engine.GetWorld();
}

GUI::~GUI()
{
}
