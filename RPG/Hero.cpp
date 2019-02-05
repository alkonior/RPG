#include "pch.h"
#include "Entities.h"
#include "HeroAI.h"


size_t Hero::_startArmor = 0;
size_t Hero::_startMaxMana = 0;
size_t Hero::_startManaRegenSpeed = 0;
size_t Hero::_startManaRegenStrong = 0;
size_t Hero::_startDmg = 0;
size_t Hero::_startSpeed = 0;
size_t Hero::_startHp = 0;

Hero::Hero(Point p)
	: IPerson(p, TEXTURES_ARAAY::T_Hero,_startHp),IHasMana(_startMaxMana/2)
	,_AI(make_shared<HeroAI>(this)) {
	_speed = _startSpeed;
}

void Hero::Init(json& description) {
	Hero::_startArmor = description["startArmor"];
	Hero::_startMaxMana = description["startMana"];
	Hero::_startManaRegenSpeed = description["startManaRegenSpeed"];
	Hero::_startManaRegenStrong = description["startManaRegenStrong"];
	Hero::_startDmg = description["startDmg"];
	Hero::_startSpeed = description["startSpeed"];
	Hero::_startHp = description["startHp"];
}

size_t Hero::getHp()
{
	return _hp;
}

size_t Hero::getMp()
{
	return _mana;
}

size_t Hero::getMaxMp()
{
	return _startMaxMana;
}

size_t Hero::getMaxHp()
{
	return _startHp;
}

ComandList Hero::_colide(IEntity* in) { return in->_colide(this); }

ComandList Hero::_colide(Hero* in) {
	return  _AI->ColideWith(this, in);
}

ComandList Hero::_colide(Wall* in) {
	return  _AI->ColideWith(this, in);
}

ComandList Hero::_colide(Zombie* z) {
	return  _AI->ColideWith(this, z);
}

ComandList Hero::_colide(Dragon *d)
{
	return  _AI->ColideWith(this, d);
}

ComandList Hero::_colide(FireBall * f)
{
	return   _AI->ColideWith(this, f);
}

ComandList Hero::_colide(Arrow *a)
{
	return   _AI->ColideWith(this, a);
}

ComandList Hero::_colide(Skeleton * s)
{
	return  _AI->ColideWith(this, s);
}

ComandList Hero::_colide(Apteca *a)
{
	return  _AI->ColideWith(this, a);
}

ComandList Hero::_colide(Princess * p)
{
	return _AI->ColideWith(this, p);
}

shared_ptr<IBaseAI> Hero::getAI()
{
	return _AI;
}

size_t Hero::getMaxMana()const
{
	return _startMaxMana;
}

void Hero::updateMana()
{
	_mana = std::min<size_t>(_mana+_startManaRegenStrong, _startMaxMana);
}

size_t Hero::getDmg() const
{
	return _startDmg;
}

size_t Hero::getMaxHp() const
{
	return _startHp;
}

size_t Hero::getArmor() const
{
	return _startArmor;
}
