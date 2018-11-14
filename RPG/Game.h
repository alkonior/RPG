#pragma once
#include "Model.h"
#include "GUI.h"
#include "Controler.h"

namespace RPG{

class Game
{
	Model Engine;
	GUI Gui;
	CONTROLER Controler;
public:
	Game(size_t);
	void start();
	void loop();
	~Game();
};

}
