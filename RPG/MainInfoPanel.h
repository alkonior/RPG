#pragma once
#include "WorldViewConstructor.h"

namespace RPG {
namespace GUINSP {
using ENGINE::WWC;

class MainInfoPanel
{
	const WWC& Data;
public:
	MainInfoPanel(WWC&);
	void Draw();
};

}//GUINSP
}//RPG