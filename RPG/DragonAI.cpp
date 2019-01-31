#include "pch.h"
#include "DragonAI.h"
#include <functional>


DragonAI::DragonAI(Dragon& d):dragon(d),step(0), searching(false)
{
}

ComandList DragonAI::getActions(const void * w, size_t)
{
	ComandList out;
	step++;
	if (step>=dragon._speed) {
		step = 0;
		const Map& world = *static_cast<const Map*>(w);
		if (dragon._cord.distance(world.hero->getCord())<=5) {
			lastSee = world.hero->getCord();
			searching = true;
		}
		if (dragon._cord.distance(lastSee)>0&&searching) {
			out.push_back(make_shared<MoveMe>(&dragon, dragon._cord.betsDir(lastSee)));
		}
		else {
			searching=false;
			auto shot_func = [](Point p) -> shared_ptr<IEntity>
			{
				return make_shared<Dragon::ShotType>(p);
			};
			vector<Point> dir{ Point(-1, 0), Point(0, -1), Point(1, 0), Point(0, 1) };
			//out.push_back(make_shared<MoveMe>(&dragon, dragon._cord.betsDir(dir[rand()%4])));
			int i = rand()%4;
			out.push_back(make_shared<Shoot>(dragon.getCord()+dir[i], dir[i],
											shared_ptr<std::function<shared_ptr<IEntity>(Point)>>(
												new std::function<shared_ptr<IEntity>(Point)>(shot_func))
											 ));
		}
	}

	return out;
}


template <>
ComandList DragonAI::ColideWith<>(Dragon* D, Hero* H) {
	ComandList out;
	out.push_back(make_shared<Attack_A_to_B>(D, H));
	out.push_back(make_shared<IfCanMoveMe>(H, D->getCord().betsDir(H->getCord())));
	out.push_back(make_shared<IfCanMoveMe>(D, D->getCord().betsDir(H->getCord())));
	return out;
}

