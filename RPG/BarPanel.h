#pragma once
#include "WorldViewConstructor.h"
namespace RPG {
namespace GUINSP {
using ENGINE::WVC;

class BarPanel
{
	const WVC& Data;
public:
	BarPanel(WVC&);
	void Draw();
};

}//GUINSP
}//RPG
