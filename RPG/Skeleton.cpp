#include "pch.h"
#include "Entities.h"
#include "SkeletonAI.h"

size_t Skeleton::_startArmor = 0;
size_t Skeleton::_startMaxMana = 0;
size_t Skeleton::_startManaRegenSpeed = 0;
size_t Skeleton::_startManaRegenStrong = 0;
size_t Skeleton::_startDmg = 0;
size_t Skeleton::_startSpeed = 0;
size_t Skeleton::_startHp = 0;

Skeleton::Skeleton(Point p):IMonster(p, TEXTURES_ARAAY::T_Skeleton,_startHp),IHasMana(_startMaxMana), _AI(make_shared<SkeletonAI>(this))
{
	_speed = _startSpeed;
}

void Skeleton::Init(json& description)
{
	_startArmor = description["startArmor"];
	_startMaxMana = description["startMana"];
	_startManaRegenSpeed = description["startManaRegenSpeed"];
	_startManaRegenStrong = description["startManaRegenStrong"];
	_startDmg = description["startDmg"];
	_startSpeed = description["startSpeed"];
	_startHp = description["startHp"];
}

ComandList Skeleton::_colide(IEntity* in)
{
	return in->_colide(this);
}

ComandList Skeleton::_colide(Hero* h)
{
	return _AI->ColideWith(this, h);
}

ComandList Skeleton::_colide(Wall* w)
{
	return _AI->ColideWith(this, w);
}

ComandList Skeleton::_colide(Zombie* z)
{
	return _AI->ColideWith(this, z);
}

ComandList Skeleton::_colide(Dragon* d)
{
	return _AI->ColideWith(this, d);
}

ComandList Skeleton::_colide(FireBall* f)
{
	return _AI->ColideWith(this, f);
}

ComandList Skeleton::_colide(Arrow* a)
{
	return _AI->ColideWith(this, a);
}

ComandList Skeleton::_colide(Skeleton* s)
{
	return _AI->ColideWith(this, s);
}

ComandList Skeleton::_colide(Apteca* a)
{
	return _AI->ColideWith(this, a);
}

ComandList Skeleton::_colide(Princess* p)
{
	return _AI->ColideWith(this, p);
}

shared_ptr<IBaseAI> Skeleton::getAI()
{
	return _AI;
}

size_t Skeleton::getDmg() const
{
	return _startDmg;
}

size_t Skeleton::getMaxHp() const
{
	return _startHp;
}

size_t Skeleton::getArmor() const
{
	return _startArmor;
}

size_t Skeleton::getMaxMana() const
{
	return _startMaxMana;
}

void Skeleton::updateMana()
{
	_mana = std::min<size_t>(_mana+_startManaRegenStrong, _startMaxMana);
}
