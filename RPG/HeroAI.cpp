#include "pch.h"
#include "HeroAI.h"
using namespace RPG::ENGINE::AI;
using namespace RPG::ENGINE;
using namespace RPG::ENGINE::WCCOMANDS;

HeroAI::HeroAI(){}

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
			break;
		}
	case'ö':
		{
			out.push_back(make_shared<MoveMeUp>());
			break;
		}
	case's':
		{
			out.push_back(make_shared<MoveMeDown>());
			break;
		}
	case'û':
		{
			out.push_back(make_shared<MoveMeDown>());
			break;
		}
	case'd':
		{
			out.push_back(make_shared<MoveMeRight>());
			break;
		}
	case'â':
		{
			out.push_back(make_shared<MoveMeRight>());
			break;
		}
	case'ô':
		{
			out.push_back(make_shared<MoveMeLeft>());
			break;
		}
	case'a':
		{
			out.push_back(make_shared<MoveMeLeft>());
			break;
		}
	default:
		break;
	}
	return out;
}
