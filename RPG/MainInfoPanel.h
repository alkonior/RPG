#pragma once
#include "WorldViewConstructor.h"

namespace RPG {
namespace GUINSP {
using ENGINE::WVC;

class MainInfoPanel
{
	const WVC& Data;
public:
	MainInfoPanel(WVC&);
	void Draw();
};

}//GUINSP
}//RPG