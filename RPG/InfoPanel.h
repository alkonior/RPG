#pragma once
#include "WorldViewConstructor.h"




class InfoPanel
{
	const WVC& Data;
public:
	InfoPanel(WVC&);
	void Draw();
};
