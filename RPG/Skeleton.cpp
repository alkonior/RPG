#include "pch.h"
#include "Entities.h"
#include "SkeletonAI.h"

size_t Skeleton::_startArmor = 0;
size_t Skeleton::_startMana = 0;
size_t Skeleton::_startDmg = 0;
size_t Skeleton::_startSpeed = 0;
size_t Skeleton::_startHp = 0;

Skeleton::Skeleton(Point p):IMonster(p, TEXTURES_ARAAY::T_Skeleton), _AI(make_shared<SkeletonAI>(this))
{
	_hp = _startHp;
	_mana = _startMana;
	_dmg = _startDmg;
	_speed = _startSpeed;
	_armor = _startArmor;
}

void Skeleton::Init(json& description)
{
	_startArmor = description["startArmor"];
	_startMana = description["startMana"];
	_startDmg = description["startDmg"];
	_startSpeed = description["startSpeed"];
	_startHp = description["startHp"];
}

ComandList Skeleton::_colide(IEntity *)
{
	return ComandList();
}

ComandList Skeleton::_colide(Hero *)
{
	return ComandList();
}

ComandList Skeleton::_colide(Wall *)
{
	return ComandList();
}

ComandList Skeleton::_colide(Zombie *)
{
	return ComandList();
}

ComandList Skeleton::_colide(Dragon *)
{
	return ComandList();
}

ComandList Skeleton::_colide(FireBall *)
{
	return ComandList();
}

ComandList Skeleton::_colide(Arrow *)
{
	return ComandList();
}

ComandList Skeleton::_colide(Skeleton *)
{
	return ComandList();
}

ComandList Skeleton::_colide(Apteca *)
{
	return ComandList();
}

ComandList Skeleton::_colide(Princess *)
{
	return ComandList();
}

shared_ptr<IBaseAI> Skeleton::getAI()
{
	return _AI;
}
