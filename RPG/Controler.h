#pragma once
#include"GUI.h"
#include"WorldViewConstructor.h"
#include"WorldControler.h"



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

