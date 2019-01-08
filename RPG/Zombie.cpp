#include "pch.h"
#include "BaseObjects.h"
#include "ZombieAI.h"

using namespace RPG;
using namespace TEXTURES;
using namespace ENTITIES;

size_t Zombie::_startArmor = 0;
size_t Zombie::_startMana = 0;
size_t Zombie::_startDmg = 0;
size_t Zombie::_startSpeed = 0;
size_t Zombie::_startHp = 0;

Zombie::Zombie(Point p):Monster(p, TEXTURES_ARAAY::T_Zombie,make_shared<ENGINE::AI::ZombieAI>())
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

bool RPG::ENTITIES::Zombie::_colide(IEntity* in)
{
	return in->_colide(this);
}

bool RPG::ENTITIES::Zombie::_colide(Hero* h)
{
	return h->getDmg(_dmg);
}

bool RPG::ENTITIES::Zombie::_colide(Wall*)
{
	return false;
}

bool RPG::ENTITIES::Zombie::_colide(Zombie*)
{
	return false;
}
