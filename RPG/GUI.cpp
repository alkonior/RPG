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
	
	vector<vector<const Texture*>> in = Engine.GetWorld(shift,Point(_w,_h));
	for (size_t i = 0; i < 20; i++)
	{
		for (size_t j = 0; j < 20; j++)
		{
			in[i][j]->Draw(Point(j, i));
		}
	}
}

GUI::~GUI()
{
}
