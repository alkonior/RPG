#include "pch.h"
#include "WorldControler.h"

using namespace RPG;
using namespace ENGINE;
using WCCOMANDS::IComand;
using WCCOMANDS::CForward;
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

RPG::ENGINE::WorldControler::WorldControler(Model& E):
	Engine(E){}

void RPG::ENGINE::WorldControler::GetComand(char)
{
	ComandList.resize(ComandList.size()+1);
	ComandList.back() = make_shared<CForward>();
	executeAll();
}

void RPG::ENGINE::WorldControler::executeAll()
{
	for(auto i = ComandList.begin();i<ComandList.end();i++)
	{
		(*i)->accept(*this);
	}
}

void CForward::accept(WorldControler& WC)
{
	WC.execute<CForward>();
}




