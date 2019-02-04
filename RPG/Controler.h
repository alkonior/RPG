#pragma once
#include"GUI.h"

class Controler
{
	
	shared_ptr<GUI> _Gui;
public:
	Controler(shared_ptr<GUI>);
	void Send(size_t);
	~Controler();
};

