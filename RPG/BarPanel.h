#pragma once
#include "WorldViewConstructor.h"




class BarPanel
{
	const WVC& Data;
public:
	BarPanel(WVC&);
	void Draw();
};

