#include "pch.h"
#include "BaseObjects.h"
using namespace RPG;
using namespace TEXTURES;
using namespace ENTITIES;


IEntity::IEntity(Point p, const Texture& t, shared_ptr<IBaseAI> ai):_cord(p),_t(t),AI(ai)
{

}

const Texture& IEntity::getTexture()
{
	return _t;
}

IPerson::IPerson(Point p, const Texture& t, shared_ptr<IBaseAI> ai):IEntity(p,t,ai){}

bool IPerson::getDmg(size_t dmg)
{
	if (dmg>_armor)
	{
		_hp -= (dmg-_armor);
		return _hp+(dmg-_armor)<(dmg-_armor);
	}
	else
	{
		return false;
	}
	
}

INotPerson::INotPerson(Point p, const Texture& t) : IEntity(p, t, nullptr) {}

Monster::Monster(Point p, const Texture& t, shared_ptr<IBaseAI> ai) : IPerson(p, t, ai) {}
