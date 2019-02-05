#include "pch.h"
#include "Entities.h"


Wall::Wall(Point p): INotPerson(p, TEXTURES_ARAAY::T_Wall) {}

ComandList Wall::_colide(IEntity* in)
{
	return in->_colide(this);;
}

shared_ptr<IBaseAI> Wall::getAI()
{
	return nullptr;
}
