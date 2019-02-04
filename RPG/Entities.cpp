#include "pch.h"
#include "Entities.h"



IEntity::IEntity(Point p, const Texture& t):_cord(p),_t(t)
{}

const Texture& IEntity::getTexture()
{
	return _t;
}

 ComandList IEntity::colide(IEntity* in) {
  if (in != nullptr) return in->_colide(this);
  return ComandList();
}
IPerson::IPerson(Point p, const Texture& t):IEntity(p,t){}

bool IPerson::getDmg(IPerson* enemy) {
  size_t dmg = enemy->_dmg;
	if (dmg>_armor)
	{
		if (dmg-_armor>_hp)
			return true;
		_hp -= (dmg-_armor);
	}
		return false;	
}

bool IPerson::getDmg(IProjectile* enemy) {
  size_t dmg = enemy->_dmg;
	if (dmg>_armor)
	{
		if (dmg-_armor>_hp)
			return true;
		_hp -= (dmg-_armor);
	}
		return false;	
}

INotPerson::INotPerson(Point p, const Texture& t) : IEntity(p, t) {}

IMonster::IMonster(Point p, const Texture& t) : IPerson(p, t) {}

IProjectile::IProjectile(Point p, const Texture & t) : IEntity(p, t)
{
}

Point IProjectile::getDir() const
{
	return _direction;
}
size_t IProjectile::getSpeed() const
{
	return _speed;
}


inline IEntity::~IEntity()
{
}
