#pragma once
#include "WorldViewConstructor.h"

namespace RPG {
namespace GUINSP {
using ENGINE::WWC;

class WorldPanel
{
	const WWC& Data;
public:
	WorldPanel(WWC&);
	void Draw();
};
}//GUINSP
}//RPG