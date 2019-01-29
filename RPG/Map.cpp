#include "pch.h"
#include "Map.h"

Map::Map(size_t seed):_seed(seed),h(0),w(0) {}

shared_ptr<IEntity>& Map::operator[](const Point& in)
{
	return World[in.y][in.x];
}



void Map::Init()
{
	switch (_seed)
	{
	case 1:
		{
			/// Тут типа нужно замутить генератор карты
			w = 20;
			h = 20;
			World.resize(h, vector<shared_ptr<IEntity>>(w, shared_ptr<IEntity>()));
			hero = make_shared<Hero>(Point(5, 15));
			(*this)[hero->getCord()] = hero;
			for (size_t i1 = 0; i1<20; i1++)
			{
				for (size_t i2 = 0; i2<20; i2++)
				{
					if ((i1==0)||(i2==0)||(i1 == 19)||(i2==19)) {
						Point p(i1,i2);
						(*this)[p] = make_shared<Wall>(p);
					}
				}
			}
			Enemies.push_back(make_shared<Zombie>(Point(1, 1)));
			(*this)[Point(1, 1)] = Enemies.back();
			break;
		}
	default:
		break;
	}
}

Map::~Map() {}
