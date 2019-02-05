#include "pch.h"
#include "Entities.h"

size_t Apteca::_startHpInc = 0;


Apteca::Apteca(Point p):INotPerson(p,TEXTURES_ARAAY::T_Apteca){}

ComandList Apteca::_colide(IEntity* in)
{
	return in->_colide(this);
}

shared_ptr<IBaseAI> Apteca::getAI()
{
	return nullptr;
}

void Apteca::Init(json& config)
{
	_startHpInc = config["startHpInc"];
}

size_t Apteca::getHpInc() const
{
	return _startHpInc;
}
