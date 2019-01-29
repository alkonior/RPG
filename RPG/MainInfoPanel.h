#pragma once
#include "WorldViewConstructor.h"



class MainInfoPanel
{
	const WVC& Data;
public:
	MainInfoPanel(WVC&);
	void Draw();
};
