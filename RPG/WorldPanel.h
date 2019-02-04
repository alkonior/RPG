#pragma once
#include "WorldViewConstructor.h"


class WorldPanel
{
	WINDOW* Window;
	size_t w, h;
public:
	WorldPanel();
	void init(Point, Point);
	void Draw(const WVC& Data) const;
	~WorldPanel();
};
