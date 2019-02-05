#include "pch.h"
#include "Entities.h"
#include "ZombieAI.h"




size_t Zombie::_startArmor = 0;
size_t Zombie::_startDmg = 0;
size_t Zombie::_startSpeed = 0;
size_t Zombie::_startHp = 0;

Zombie::Zombie(Point p):IMonster(p, TEXTURES_ARAAY::T_Zombie, _startHp), _AI(make_shared<ZombieAI>(*this))
{
	_speed = _startSpeed;
}

void Zombie::Init(json& description)
{
	_startArmor = description["startArmor"];
	_startDmg = description["startDmg"];
	_startSpeed = description["startSpeed"];
	_startHp = description["startHp"];
}

ComandList Zombie::_colide(IEntity* in)
{
	return in->_colide(this);
}

ComandList Zombie::_colide(Hero* h) {
	return  _AI->ColideWith(this, h);
}

ComandList Zombie::_colide(Wall* w) {
	return  _AI->ColideWith(this, w);
}

ComandList Zombie::_colide(Zombie* z) {
	return  _AI->ColideWith(this, z);
}

ComandList Zombie::_colide(Dragon * d)
{
	return   _AI->ColideWith(this, d);
}

ComandList Zombie::_colide(FireBall * f)
{
	return   _AI->ColideWith(this, f);
}

ComandList Zombie::_colide(Arrow * a)
{
	return   _AI->ColideWith(this, a);
}

ComandList Zombie::_colide(Skeleton * s)
{
	return _AI->ColideWith(this, s);
}

ComandList Zombie::_colide(Apteca * a)
{
	return _AI->ColideWith(this, a);
}

ComandList Zombie::_colide(Princess * p)
{
	return _AI->ColideWith(this, p);
}

shared_ptr<IBaseAI> Zombie::getAI()
{
	return _AI;
}

size_t Zombie::getDmg() const
{
	return _startDmg;
}

size_t Zombie::getMaxHp() const
{
	return _startHp;
}

size_t Zombie::getArmor() const
{
	return _startArmor;
}


