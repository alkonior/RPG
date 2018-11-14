#pragma once
#include "WorldViewConstructor.h"
namespace RPG {
namespace GUINSP {
using ENGINE::WWC;

class BarPanel
{
	const WWC& Data;
public:
	BarPanel(WWC&);
	void Draw();
};

}//GUINSP
}//RPG
