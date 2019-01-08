#include "pch.h"
#include "WorldControler.h"

using namespace RPG;
using namespace ENGINE;
using BASECNTROLER::IComand;
using WCCOMANDS::CForward;
using WCCOMANDS::MoveMeUp;

RPG::ENGINE::WorldControler::WorldControler(Model& E):
	World(E.World){}

void RPG::ENGINE::WorldControler::GetComand(size_t comand)
{
	ComandList =  World.hero->getAI()->getActions(&World, World.hero.get(), comand);
	curObject = World.hero;
	executeAll();
	
}

void RPG::ENGINE::WorldControler::executeAll()
{
	for(auto i = ComandList.begin();i<ComandList.end();i++)
	{
		(*i)->accept(*this);
	}
}




