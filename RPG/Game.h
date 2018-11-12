#pragma once
#include "Map.h"
#include "GUI.h"

class Game
{
	Map Engine;
	GUI Gui;
public:
	Game(size_t width,size_t height);
	void start();
	void loop();
	~Game();
};

