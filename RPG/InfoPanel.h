#pragma once
#include "WorldViewConstructor.h"

namespace RPG {
namespace GUINSP {
using ENGINE::WWC;

class InfoPanel
{
	const WWC& Data;
public:
	InfoPanel(WWC&);
	void Draw();
};
}//GUINSP
}//RPG
