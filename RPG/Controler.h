#pragma once
#include"GUI.h"
#include"Model.h"
namespace RPG {
using GUINSP::GUI;
using ENGINE::Model;

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