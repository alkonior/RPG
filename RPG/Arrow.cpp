#include "pch.h"
#include "Entities.h"
#include "ProjectileAI.h"



size_t Arrow::_startDmg = 0;
size_t Arrow::_startSpeed = 0;
size_t Arrow::_startManaCost = 10000;

void Arrow::Init(json& description) {
	Arrow::_startDmg = description["startDmg"];
	Arrow::_startSpeed = description["startSpeed"];
	Arrow::_startManaCost = description["startManaCost"];
}

Arrow::Arrow(Point p, Point dir):IProjectile(p, TEXTURES_ARAAY::T_Arrow), _AI(make_shared<ProjectileAI<Skeleton>>(this))
{
	_speed = _startSpeed;
	_direction = dir;
}

ComandList Arrow::_colide(IEntity* in)
{
	return in->_colide(this);
}

ComandList Arrow::_colide(Hero* h)
{
	return _AI->ColideWith(this, h);
}

ComandList Arrow::_colide(Wall* w)
{
	return _AI->ColideWith(this, w);
}

ComandList Arrow::_colide(Zombie* z)
{
	return _AI->ColideWith(this, z);
}

ComandList Arrow::_colide(Dragon* d)
{
	return _AI->ColideWith(this, d);
}

ComandList Arrow::_colide(FireBall* f)
{
	return _AI->ColideWith(this, f);
}

ComandList Arrow::_colide(Arrow* a)
{
	return _AI->ColideWith(this, a);
}

ComandList Arrow::_colide(Skeleton* s)
{
	return _AI->ColideWith(this, s);
}

ComandList Arrow::_colide(Apteca* a)
{
	return _AI->ColideWith(this, a);
}

ComandList Arrow::_colide(Princess *p)
{
	return _AI->ColideWith(this, p);
}

shared_ptr<IBaseAI> Arrow::getAI()
{
	return _AI;
}

size_t Arrow::getManaCost() const
{
	return _startManaCost;
}

size_t Arrow::getDmg() const
{
	return _startDmg;
}
