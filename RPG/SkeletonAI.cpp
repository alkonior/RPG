#include "pch.h"
#include "SkeletonAI.h"


shared_ptr<IProjectile> SkeletonAI::generator(Point p, Point dir)
{
	return make_shared<Skeleton::ShotType>(p, dir);
}

SkeletonAI::SkeletonAI(Skeleton* s):skeleton(s) {
}
shared_ptr<Shoot::func_t> SkeletonAI::func = shared_ptr<Shoot::func_t>(new Shoot::func_t(
	[](Point p, Point dir)->shared_ptr<IProjectile>
{
	return make_shared<Skeleton::ShotType>(p, dir);
}
));

ComandList SkeletonAI::getActions(const void* w, size_t)
{
	ComandList out;
	step++;
	if (step>=skeleton->_speed) {
		step = 0;
		const Map& world = *static_cast<const Map*>(w);
		auto h = world.hero.lock()->getCord();
		if (skeleton->_cord.distance(h)<=4) {
			if (world[skeleton->getCord()-skeleton->_cord.betsDir(h)]==nullptr)
				out.push_back(make_shared<MoveMe>(skeleton, -skeleton->_cord.betsDir(h)));
			else
				if (skeleton->_cord.x==h.x||skeleton->_cord.y==h.y)
				{
					out.push_back(make_shared<Shoot>(skeleton, skeleton->_cord.betsDir(h), skeleton, func));
				}

		}
		else {
			if (skeleton->_cord.distance(h)<=8)
			{
				if (skeleton->_cord.x==h.x||skeleton->_cord.y==h.y)
				{
					out.push_back(make_shared<Shoot>(skeleton, skeleton->_cord.betsDir(h), skeleton, func));
				}
			}
		}
	}
	return out;
}

