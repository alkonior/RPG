#include "pch.h"
#include "Controler.h"
using namespace RPG;
using namespace GUINSP;
using namespace ENGINE;

Controler::Controler(GUI& G, Model& E):
	Gui(G),
	Engine(E),
	WC(Engine)
{}

void Controler::Send(size_t in)
{
	if (!Gui.Comand(in))
	{
		WC.GetComand(in);
	}
}

Controler::~Controler()
{
}
