#pragma once
#include"GUI.h"
#include"Model.h"

class CONTROLER
{
	GUI& Gui;
	Model& Engine;

public:
	CONTROLER(GUI&,	Model&);
	void Send(size_t);
	~CONTROLER();
};

