#pragma once
#include "Map.h"

class GUI
{
	Map& Engine;
public:
	GUI(Map&);
	void Draw();
	void Send(int);
	~GUI();
};

