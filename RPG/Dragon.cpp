#include "pch.h"
#include "Entities.h"
#include "DragonAI.h"

size_t Dragon::_startArmor = 0;
size_t Dragon::_startMaxMana = 0;
size_t Dragon::_startManaRegenSpeed = 0;
size_t Dragon::_startManaRegenStrong = 0;
size_t Dragon::_startDmg = 0;
size_t Dragon::_startSpeed = 0;
size_t Dragon::_startHp = 0;

Dragon::Dragon(Point p):IMonster(p, TEXTURES_ARAAY::T_Dragon, _startHp),
IHasMana(_startMaxMana/2), _AI(make_shared<DragonAI>(this))
{
	_speed = _startSpeed;
}

void Dragon::Init(json& description)
{
	_startArmor = description["startArmor"];
	_startMaxMana = description["startMana"];
	_startManaRegenSpeed = description["startManaRegenSpeed"];
	_startManaRegenStrong = description["startManaRegenStrong"];
	_startDmg = description["startDmg"];
	_startSpeed = description["startSpeed"];
	_startHp = description["startHp"];
}

ComandList Dragon::_colide(IEntity * in)
{
	return in->_colide(this);
}

ComandList Dragon::_colide(Hero * h)
{
	return _AI->ColideWith(this, h);
}

ComandList Dragon::_colide(Wall * w)
{
	return  _AI->ColideWith(this, w);
}

ComandList Dragon::_colide(Zombie * z)
{
	return  _AI->ColideWith(this, z);
}

ComandList Dragon::_colide(Dragon * d)
{
	return  _AI->ColideWith(this, d);
}

ComandList Dragon::_colide(FireBall * f)
{
	return  _AI->ColideWith(this, f);
}

ComandList Dragon::_colide(Arrow * a)
{
	return  _AI->ColideWith(this, a);
}

ComandList Dragon::_colide(Skeleton * s)
{
	return _AI->ColideWith(this, s);
}

ComandList Dragon::_colide(Apteca * a)
{
	return _AI->ColideWith(this, a);
}

ComandList Dragon::_colide(Princess* p)
{
	return _AI->ColideWith(this, p);
}

shared_ptr<IBaseAI> Dragon::getAI()
{
	return _AI;
}

size_t Dragon::getMaxHp()const 
{
	return _startHp;
}

size_t Dragon::getMaxMana()const
{
	return _startMaxMana;
}

void Dragon::updateMana()
{
	_mana = std::min<size_t>(_mana+_startManaRegenStrong, _startMaxMana);
}

size_t Dragon::getDmg() const
{
	return _startDmg;
}

size_t Dragon::getArmor() const
{
	return _startArmor;
}
