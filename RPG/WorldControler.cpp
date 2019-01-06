#include "pch.h"
#include "WorldControler.h"

using namespace RPG;
using namespace ENGINE;
using BASECNTROLER::IComand;
using WCCOMANDS::CForward;
using WCCOMANDS::MoveMeUp;
using std::vector;

template<class T>
void WorldControler::execute()
{
	std::cerr<<"WorldConteroler Unnoun comand";
}

template<>
void WorldControler::execute<CForward>()
{
	std::cerr<<"WorldConteroler Forward yeee";
}
template<>
void WorldControler::execute<MoveMeUp>()
{
	std::cerr<<"WorldConteroler Forward yeee";
}

RPG::ENGINE::WorldControler::WorldControler(Model& E):
	World(E.World){}

void RPG::ENGINE::WorldControler::GetComand(size_t comand)
{
	ComandList =  World.hero->getAI()->getActions(&World, &*World.hero, comand);
	executeAll();
}

void RPG::ENGINE::WorldControler::executeAll()
{
	for(auto i = ComandList.begin();i<ComandList.end();i++)
	{
		(*i)->accept(*this);
	}
}




