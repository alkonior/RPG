#pragma once
#include "WorldViewConstructor.h"

namespace RPG {
namespace GUINSP {
using ENGINE::WVC;
using TEXTURES::Point;

class WorldPanel
{
	const WVC& Data;
	WINDOW* Window;
	PANEL* Panel;
	size_t w, h;
public:
	WorldPanel(WVC&);
	void init(Point, Point);
	void Draw();
	~WorldPanel();
};
}//GUINSP
}//RPG