#include "pch.h"
#include "Entities.h"
#include "ProjectileAI.h"

size_t FireBall::_startDmg = 0;
size_t FireBall::_startSpeed = 0;
size_t FireBall::_startManaCost = 10000;

void FireBall::Init(json& description) {
	FireBall::_startDmg = description["startDmg"];
	FireBall::_startSpeed = description["startSpeed"];
	FireBall::_startManaCost = description["startManaCost"];
}

FireBall::FireBall(Point p, Point dir):IProjectile(p, TEXTURES_ARAAY::T_FireBall),_AI(make_shared<ProjectileAI<Dragon>>(this))
{
	_speed = _startSpeed;
	_direction = dir;
}

ComandList FireBall::_colide(IEntity * in)
{
	return in->_colide(this);
}

ComandList FireBall::_colide(Hero* h)
{
	return _AI->ColideWith(this, h);
}

ComandList FireBall::_colide(Wall* w)
{
	return _AI->ColideWith(this, w);
}

ComandList FireBall::_colide(Zombie* z)
{
	return _AI->ColideWith(this, z);
}

ComandList FireBall::_colide(Dragon* d)
{
	return _AI->ColideWith(this, d);
}

ComandList FireBall::_colide(FireBall* f)
{
	return _AI->ColideWith(this, f);
}

ComandList FireBall::_colide(Arrow* a)
{
	return _AI->ColideWith(this, a);
}

ComandList FireBall::_colide(Skeleton* s)
{
	return _AI->ColideWith(this, s);
}

ComandList FireBall::_colide(Princess* p)
{
	return _AI->ColideWith(this, p);
}

ComandList FireBall::_colide(Apteca* a)
{
	return _AI->ColideWith(this, a);
}

shared_ptr<IBaseAI> FireBall::getAI()
{
	return _AI;
}

size_t FireBall::getManaCost() const
{
	return _startManaCost;
}

size_t FireBall::getDmg() const
{
	return _startDmg;
}
