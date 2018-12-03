#pragma once
#include"GUI.h"
#include"WorldViewConstructor.h"
#include"WorldControler.h"

namespace RPG {
using GUINSP::GUI;
using ENGINE::Model;
using ENGINE::WorldControler;

class Controler
{
	
	GUI& Gui;
	Model& Engine;
	WorldControler WC;

public:
	Controler(GUI&, Model&);
	void Send(size_t);
	~Controler();
};

} //RPG