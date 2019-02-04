#include "pch.h"
#include "Entities.h"
#include "DragonAI.h"

size_t Dragon::_startArmor = 0;
size_t Dragon::_startMana = 0;
size_t Dragon::_startDmg = 0;
size_t Dragon::_startSpeed = 0;
size_t Dragon::_startHp = 0;

Dragon::Dragon(Point p):IMonster(p, TEXTURES_ARAAY::T_Dragon),_AI(make_shared<DragonAI>(*this))
{
	_hp = _startHp;
	_mana = _startMana;
	_dmg = _startDmg;
	_speed = _startSpeed;
	_armor = _startArmor;
}

void Dragon::Init(json& description)
{
	_startArmor = description["startArmor"];
	_startMana = description["startMana"];
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

shared_ptr<IBaseAI> Dragon::getAI()
{
	return _AI;
}
