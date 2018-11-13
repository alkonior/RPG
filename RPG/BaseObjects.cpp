#include "pch.h"
#include "BaseObjects.h"

Hero::Hero(Point p):IPerson(Textures::T_Hero(),p)
{

}

Wall::Wall(Point)
{
}

IEntity::IEntity(Texture t,Point p):t(t),cord(p),hp(0)
{
}

IPerson::IPerson(Texture t,Point p): IEntity(t,p){}
