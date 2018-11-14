#pragma once
#include "WorldViewConstructor.h"

namespace RPG {
namespace GUINSP {
using ENGINE::WWC;
using TEXTURES::Point;

class WorldPanel
{
	const WWC& Data;
	WINDOW* Window;
	PANEL* Panel;
	size_t w, h;
public:
	WorldPanel(WWC&);
	void init(Point, Point);
	void Draw();
	~WorldPanel();
};
}//GUINSP
}//RPG