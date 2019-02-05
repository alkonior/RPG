#include "pch.h"
#include "Map.h"

Map::Map(size_t seed):_seed(seed),height(0),width(0) {}

shared_ptr<IEntity>& Map::operator[](const Point& in)
{
	return World[in.y][in.x];
}

const shared_ptr<IEntity>& Map::operator[](const Point & in) const
{
	return World[in.y][in.x];
}

void Map::Delete(Point p)
{
	this->operator[](p) =shared_ptr<IEntity>();
}

void Map::addEnemy(shared_ptr<IMonster> e)
{
	(*this)[e->getCord()] = e;
	Enemies.emplace_back(e);
}

void Map::addProjectile(shared_ptr<IProjectile> p)
{
	(*this)[p->getCord()] = p;
	Projectiles.emplace_back(p);
}


void Map::Init()
{
	switch (_seed)
	{
	case 1:
		{
			/// Тут типа нужно замутить генератор карты
			width =60;
			height = 40;
			World.resize(height, vector<shared_ptr<IEntity>>(width, shared_ptr<IEntity>()));		
			auto h = make_shared<Hero>(Point(1, 1));
			(*this)[Point(1, 1)] = h;
			hero = h;
			for (size_t i1 = 0; i1<60; i1++)
			{
				for (size_t i2 = 0; i2<40; i2++)
				{
					if ((i1==0)||(i2==0)||(i1 == 59)||(i2==39)) {
						Point p(i1,i2);
						(*this)[p] = make_shared<Wall>(p);
					}
				}
			}

			//addEnemy(make_shared<Zombie>(Point(5, 1)));	
			//addEnemy(make_shared<Dragon>(Point(5,5)));	
			addEnemy(make_shared<Skeleton>(Point(7,5)));	
			break;
		}
	default:
		break;
	}
}

Map::~Map() {}
