#pragma once
#include "Model.h"

#define BaseShiftX 5
#define BaseShiftY 5

class GUI
{
	Point shift;
	size_t _w;
	size_t _h;
	Model& Engine;
public:
	GUI(Model&);
	void init(size_t, size_t);
	bool Comand(size_t);
	void Draw();
	~GUI();
};

