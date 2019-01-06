#include "pch.h"
#include "HeroAI.h"
using namespace RPG::ENGINE::AI;
using namespace RPG::ENGINE;
using namespace RPG::ENGINE::WCCOMANDS;

HeroAI::HeroAI()
{
}


HeroAI::~HeroAI()
{
}

vector<shared_ptr<IComand>> RPG::ENGINE::AI::HeroAI::getActions(const void* w, const void* h, size_t comand)
{
	const ENTITIES::Hero* hero= static_cast<const ENTITIES::Hero*>(h);
	const Map* world= static_cast<const Map*>(w);
	vector<shared_ptr<IComand>> out;
	switch (comand)
	{
	case'w':
		{
			out.push_back(make_shared<MoveMeUp>());
		}
	default:
		break;
	}
	return out;
}
