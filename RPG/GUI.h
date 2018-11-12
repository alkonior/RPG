#pragma once
#include "Map.h"

class GUI
{
	size_t w;
	size_t h;
	Map& Engine;
public:
	GUI(Map&);
	void Draw();
	void Send(int);
	~GUI();
};

