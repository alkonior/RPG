#include "pch.h"
#include "Entities.h"


IEntity::IEntity(Point p, const Texture& t, shared_ptr<IBaseAI> ai):_cord(p),_t(t),AI(ai)
{}

const Texture& IEntity::getTexture()
{
	return _t;
}

 ComandList IEntity::colide(IEntity* in) {
  if (in != nullptr) return in->_colide(this);
  return ComandList();
}
IPerson::IPerson(Point p, const Texture& t, shared_ptr<IBaseAI> ai):IEntity(p,t,ai){}

bool IPerson::getDmg(IPerson* enemy) {
  size_t dmg = enemy->_dmg;
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