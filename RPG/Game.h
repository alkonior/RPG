#pragma once
#include "Model.h"
#include "GUI.h"
#include "Controler.h"

namespace RPG {




class Game
{
	Model Engine;
	GUI Gui;
	Controler Controler;
public:
	Game(json&);
	void start();
	void loop();
	~Game();
};

}
