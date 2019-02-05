#include "pch.h"
#include "Map.h"

Map::Map(vector<std::string> v,json& config):height(v.size()), width(v[0].length())
{
	Hero::Init(config["hero"]);
	Zombie::Init(config["zombie"]);
	Skeleton::Init(config["skeleton"]);
	Dragon::Init(config["dragon"]);
	FireBall::Init(config["fireball"]);
	Arrow::Init(config["arrow"]);
	Apteca::Init(config["apteca"]);

	World.resize(height, vector<shared_ptr<IEntity>>(width, shared_ptr<IEntity>()));
 	for (size_t i = 0; i<height; i++)
	{
		for (size_t j = 0; j<width; j++)
		{
			switch (v[i][j]) {
			case 'w': {
					(*this)[Point(j, i)] = make_shared<Wall>(Point(j, i));
					break;
				};
			case 'h': {
					auto h= make_shared<Hero>(Point(j, i));
					(*this)[Point(j, i)] = h;
					hero = h;
					break;
				}
			case 'z': {
					addEnemy(make_shared<Zombie>(Point(j, i)));
					break;
				}
			case 's': {
					addEnemy(make_shared<Skeleton>(Point(j, i)));
					break;
				}
			case 'd': {
					addEnemy(make_shared<Dragon>(Point(j, i)));
					break;
				}
			case 'a': {
					(*this)[Point(j, i)] = make_shared<Apteca>(Point(j, i));
					break;
				}
			case 'p': {
					//(*this)[Point(j, i)] = make_shared<Princess>(Point(j, i));
					break;
				}

			}
		}
	}

}

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
	this->operator[](p) = shared_ptr<IEntity>();
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


Map::~Map() {}
