#pragma once
#include "WorldViewConstructor.h"

namespace RPG {
namespace GUINSP {
using ENGINE::WVC;

class InfoPanel
{
	const WVC& Data;
public:
	InfoPanel(WVC&);
	void Draw();
};
}//GUINSP
}//RPG
