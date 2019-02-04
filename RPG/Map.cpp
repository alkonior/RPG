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
			width =1000;
			height = 1000;
			World.resize(height, vector<shared_ptr<IEntity>>(width, shared_ptr<IEntity>()));		
			auto h = make_shared<Hero>(Point(400, 400));
			(*this)[Point(400, 400)] = h;
			hero = h;
			for (size_t i1 = 0; i1<1000; i1++)
			{
				for (size_t i2 = 0; i2<1000; i2++)
				{
					if ((i1==0)||(i2==0)||(i1 == 19)||(i2==19)) {
						Point p(i1,i2);
						(*this)[p] = make_shared<Wall>(p);
					}
				}
			}
			
			for (size_t i = 0; i<350; i++)
			{
				addEnemy(make_shared<Zombie>(Point(i+1, i+1)));
				addEnemy(make_shared<Zombie>(Point(406+i,400)));
			}
			addEnemy(make_shared<Zombie>(Point(1, 1)));	
			addEnemy(make_shared<Dragon>(Point(5,5)));	
			break;
		}
	default:
		break;
	}
}

Map::~Map() {}
