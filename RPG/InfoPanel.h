#pragma once
#include "WorldViewConstructor.h"




class InfoPanel
{
	const WVC& Data;
	WINDOW* Window;
	size_t w, h;
public:
	InfoPanel(WVC&);
	void init(Point, Point);
	void Draw();
};
