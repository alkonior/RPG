#include "pch.h"
#include "Entities.h"
#include "ProjectileAI.h"



size_t Arrow::_startDmg = 0;
size_t Arrow::_startSpeed = 0;

void Arrow::Init(json& description) {
	Arrow::_startDmg = description["startDmg"];
	Arrow::_startSpeed = description["startSpeed"];
}

Arrow::Arrow(Point p, Point dir):IProjectile(p, TEXTURES_ARAAY::T_FireBall), _AI(make_shared<ProjectileAI<Skeleton>>(this))
{
	_speed = _startSpeed;
	_dmg = _startDmg;
	_direction = dir;
}

ComandList Arrow::_colide(IEntity* in)
{
	return in->_colide(this);
}

ComandList Arrow::_colide(Hero *)
{
	return ComandList();
}

ComandList Arrow::_colide(Wall *)
{
	return ComandList();
}

ComandList Arrow::_colide(Zombie *)
{
	return ComandList();
}

ComandList Arrow::_colide(Dragon *)
{
	return ComandList();
}

ComandList Arrow::_colide(FireBall *)
{
	return ComandList();
}

ComandList Arrow::_colide(Arrow *)
{
	return ComandList();
}
