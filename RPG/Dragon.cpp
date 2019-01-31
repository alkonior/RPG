#include "pch.h"
#include "Entities.h"
#include "DragonAI.h"

size_t Dragon::_startArmor = 0;
size_t Dragon::_startMana = 0;
size_t Dragon::_startDmg = 0;
size_t Dragon::_startSpeed = 0;
size_t Dragon::_startHp = 0;

Dragon::Dragon(Point p):Monster(p, TEXTURES_ARAAY::T_Dragon, make_shared<DragonAI>(*this))
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
	return dynamic_cast<DragonAI*>(&(*AI))->ColideWith(this, h);
}

ComandList Dragon::_colide(Wall * w)
{
	return dynamic_cast<DragonAI*>(&(*AI))->ColideWith(this, w);
}

ComandList Dragon::_colide(Zombie * z)
{
	return dynamic_cast<DragonAI*>(&(*AI))->ColideWith(this, z);
}

ComandList Dragon::_colide(Dragon * d)
{
	return dynamic_cast<DragonAI*>(&(*AI))->ColideWith(this, d);
}
