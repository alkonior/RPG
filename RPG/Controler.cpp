#include "pch.h"
#include "Controler.h"


Controler::Controler(shared_ptr<GUI>g):_Gui(g)
{}

void Controler::Send(size_t in)
{

	auto res = _Gui->getComand(in);
	if (res)
	{
		_Gui->setScene(res);
	}
	_Gui->Draw();
}

Controler::~Controler()
{
}
