#pragma once

#include "Model.h"
#include "GUI.h"
#include "Controler.h"





class Game
{
	Model _Engine;
	GUI _Gui;
	Controler _Controler;
public:
	Game(json&);
	void start();
	void loop();
	~Game();
};

