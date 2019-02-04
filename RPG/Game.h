#pragma once

#include "GUI.h"
#include "Controler.h"





class Game
{
	shared_ptr<GUI> _Gui;
	Controler _Controler;

public:
	Game(json&);
	void start();
	void loop();
	~Game();
};

