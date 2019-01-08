#include "pch.h"
#include "BaseObjects.h"
using namespace RPG;
using namespace TEXTURES;
using namespace ENTITIES;


Wall::Wall(Point p):INotPerson(p, TEXTURES_ARAAY::T_Wall)
{}

bool Wall::_colide(IEntity* in)
{
	return in->_colide(this);
}

bool Wall::_colide(Hero* in)
{
	return false;
}

bool Wall::_colide(Wall* in)
{
	return false;
}

bool Wall::_colide(Zombie *)
{
	return false;
}
