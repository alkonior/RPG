#include "pch.h"
#include "Controler.h"
using namespace RPG;
using namespace GUINSP;
using namespace ENGINE;

CONTROLER::CONTROLER(GUI& G, Model& E) :Gui(G), Engine(E){}

void CONTROLER::Send(size_t in)
{
	if (!Gui.Comand(in))
	{
		Engine.Comand(in);
	}
}

CONTROLER::~CONTROLER()
{
}
