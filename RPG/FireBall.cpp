#include "pch.h"
#include "Entities.h"
#include "FireBallAI.h"



FireBall::FireBall(Point p,Point dir):IProjectile(p,TEXTURES_ARAAY::T_FireBall,make_shared<FireBallAI>(*this))
{
}

ComandList FireBall::_colide(IEntity * in)
{
	return in->_colide(this);
}

ComandList FireBall::_colide(Hero* h)
{
	return dynamic_cast<FireBallAI*>(AI.get())->ColideWith(this, h);
}

ComandList FireBall::_colide(Wall* w)
{
	return dynamic_cast<FireBallAI*>(AI.get())->ColideWith(this, w);
}

ComandList FireBall::_colide(Zombie* z)
{
	return dynamic_cast<FireBallAI*>(AI.get())->ColideWith(this, z);
}

ComandList FireBall::_colide(Dragon* d)
{
	return dynamic_cast<FireBallAI*>(AI.get())->ColideWith(this, d);
}

ComandList FireBall::_colide(FireBall* f)
{
	return dynamic_cast<FireBallAI*>(AI.get())->ColideWith(this, f);
}

ComandList FireBall::_colide(Arrow* a)
{
	return dynamic_cast<FireBallAI*>(AI.get())->ColideWith(this, a);
}
