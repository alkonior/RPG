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

IPerson::IPerson(Point p, const Texture& t, size_t hp):IEntity(p,t),IHasHp(hp){}

INotPerson::INotPerson(Point p, const Texture& t) : IEntity(p, t) {}

IMonster::IMonster(Point p, const Texture& t,  size_t hp) : IPerson(p, t,hp) {}

IProjectile::IProjectile(Point p, const Texture & t) : IEntity(p, t){}

Point IProjectile::getDir() const
{
	return _direction;
}
size_t IProjectile::getSpeed() const
{
	return _speed;
}

IEntity::~IEntity(){}

IHasMana::IHasMana(size_t m):_mana(m)
{
}

bool IHasMana::canShoot(IHasManaCost* p)
{
	size_t i = p->getManaCost();
	if (_mana>=i)
	{
		_mana -= i;
		return true;
	}
	return false;
}


IHasHp::IHasHp(size_t hp):_hp(hp){}

bool IHasHp::attack(IHasDmg* enemy)
{
	size_t dmg = enemy->getDmg();
	if (dmg>getArmor())
	{
		if (dmg-getArmor()>_hp)
			return true;
		_hp -= (dmg-getArmor());
	}
	return false;
}
