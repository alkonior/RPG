#include "pch.h"
#include "BaseObjects.h"

Hero::Hero(Point p):IPerson(p,&Textures::T_Hero)
{
	
}

Wall::Wall(Point p):INotPerson(p, &Textures::T_Wall)
{
}

IEntity::IEntity(Point p, const Texture* t):_cord(p),_t(t)
{
}

const Texture*IEntity::getTexture() 
{
	return _t;
}

IPerson::IPerson(Point p, const Texture* t):IEntity(p,t){}

INotPerson::INotPerson(Point p, const Texture* t) : IEntity(p,t) {}
