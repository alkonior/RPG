#include "pch.h"
#include "Entities.h"


Wall::Wall(Point p): INotPerson(p, TEXTURES_ARAAY::T_Wall) {}

ComandList Wall::_colide(IEntity* in) { return in->_colide(this); }

ComandList Wall::_colide(Hero* in) { return ComandList(); }

ComandList Wall::_colide(Wall* in) { return ComandList(); }

ComandList Wall::_colide(Zombie*) { return ComandList(); }

ComandList Wall::_colide(Dragon *) { return ComandList(); }

ComandList Wall::_colide(FireBall *){return ComandList(); }

ComandList Wall::_colide(Arrow *){	return ComandList(); }

shared_ptr<IBaseAI> Wall::getAI()
{
	return nullptr;
}
