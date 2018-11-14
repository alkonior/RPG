#pragma once
#include"GUI.h"
#include"WorldViewConstructor.h"

namespace RPG {
using GUINSP::GUI;
using ENGINE::Model;
using ENGINE::WorldViewConstructor;

class CONTROLER
{
	
	GUI& Gui;
	Model& Engine;

public:
	CONTROLER(GUI&, Model&);
	void Send(size_t);
	~CONTROLER();
};

} //RPG