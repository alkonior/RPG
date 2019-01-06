#include "pch.h"
#include "Map.h"
using namespace RPG::ENGINE;
using namespace RPG::ENTITIES;
Map::Map(size_t seed):_seed(seed),h(0),w(0) {}

void RPG::ENGINE::Map::Init()
{
	switch (_seed)
	{
	case 1:
		{
			/// Тут типа нужно замутить генератор карты
			w = 20;
			h = 20;
			World.resize(h, vector<shared_ptr<IEntity>>(w, shared_ptr<IEntity>()));
			hero = make_shared<Hero>(Point(1, 5));
			World[1][5] = hero;

		}
	default:
		break;
	}
}

Map::~Map() {}
