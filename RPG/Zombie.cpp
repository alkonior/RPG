#include "pch.h"
#include "Entities.h"
#include "ZombieAI.h"




size_t Zombie::_startArmor = 0;
size_t Zombie::_startMana = 0;
size_t Zombie::_startDmg = 0;
size_t Zombie::_startSpeed = 0;
size_t Zombie::_startHp = 0;

Zombie::Zombie(Point p):Monster(p, TEXTURES_ARAAY::T_Zombie,make_shared<ZombieAI>())
{
	_hp = _startHp;
	_mana = _startMana;
	_dmg = _startDmg;
	_speed = _startSpeed;
	_armor = _startArmor;
}

void Zombie::Init(json& description)
{
	_startArmor = description["startArmor"];
	_startMana = description["startMana"];
	_startDmg = description["startDmg"];
	_startSpeed = description["startSpeed"];
	_startHp = description["startHp"];
}

ComandList Zombie::_colide(IEntity* in)
{
	return in->_colide(this);
}

ComandList Zombie::_colide(Hero* h) {
	  if (h->getDmg(_dmg)) {
    return ComandList();
  } else {
    return ComandList();
  }
}

ComandList Zombie::_colide(Wall*) { return ComandList(); }

ComandList Zombie::_colide(Zombie*) { return ComandList(); }
