#include "pch.h"
#include "DragonAI.h"
#include <functional>



DragonAI::DragonAI(Dragon* d):dragon(d), step(0), searching(false) {}

shared_ptr<IProjectile> DragonAI::generator(Point p, Point dir)
{
	return make_shared<Dragon::ShotType>(p, dir);
}

ComandList DragonAI::getActions(const void * w, size_t)
{
	ComandList out;
	step++;
	if (step>=dragon->_speed) {
		step = 0;
		const Map& world = *static_cast<const Map*>(w);
		if (dragon->_cord.distance(world.hero.lock()->getCord())<=5) {
			lastSee = world.hero.lock()->getCord();
			searching = true;
		}
		if (dragon->_cord.distance(lastSee)>0&&searching) {
			out.push_back(make_shared<MoveMe>(dragon, dragon->_cord.betsDir(lastSee)));
		}
		else {
			searching = false;
			vector<Point> dir{ Point(-1, 0), Point(0, -1), Point(1, 0), Point(0, 1) };
			//out.push_back(make_shared<MoveMe>(&dragon, dragon._cord.betsDir(dir[rand()%4])));
			int i = rand()%4;

			out.push_back(make_shared<Shoot>(dragon, dir[i], shared_ptr<Shoot::finc_t>( new Shoot::finc_t(&generator)), Dragon::ShotType::_manaCost));
		}
	}

	return out;
}


template <>
ComandList DragonAI::ColideWith<>(Dragon* D, Hero* H) {
	ComandList out;
	out.push_back(make_shared<Attack_A_to_B>(D, H));
	out.push_back(make_shared<PushMe>(H, D->getCord().betsDir(H->getCord())));
	out.push_back(make_shared<PushMe>(D, D->getCord().betsDir(H->getCord())));
	return out;
}

