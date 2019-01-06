#include "pch.h"
#include "BaseObjects.h"
using namespace RPG;
using namespace TEXTURES;
using namespace Entities;


IEntity::IEntity(Point p, const Texture& t):_cord(p),_t(t)
{

}

const Texture& IEntity::getTexture()
{
	return _t;
}

IPerson::IPerson(Point p, const Texture& t):IEntity(p,t){}

INotPerson::INotPerson(Point p, const Texture& t) : IEntity(p,t) {}
