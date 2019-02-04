#pragma once
#include "WorldViewConstructor.h"




class InfoPanel
{
	WINDOW* Window;
	size_t w, h;
public:
	InfoPanel();
	void init(Point, Point);
	void Draw(const WVC& Data);
};
