#pragma once
#include "WorldViewConstructor.h"




class InfoPanel
{
	const WVC& Data;
	WINDOW* Window;
	PANEL* Panel;
	size_t w, h;
public:
	InfoPanel(WVC&);
	void init(Point, Point);
	void Draw();
};
