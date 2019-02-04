#include "pch.h"
#include "HeroAI.h"


shared_ptr<IProjectile> HeroAI::generator(Point p, Point dir)
{
	return make_shared<Hero::ShotType>(p, dir);
}

HeroAI::HeroAI(Hero* h): hero(h) {}

ComandList HeroAI::getActions(const void *w, size_t comand)
{
	const Map *world = static_cast<const Map *>(w);
	vector<shared_ptr<IComand>> out;
	switch (comand) {
	case 'w': {
			out.push_back(make_shared<MoveMe>(hero, Point(0, -1)));
			break;
		}
	case 's': {
			out.push_back(make_shared<MoveMe>(hero, Point(0, 1)));
			break;
		}
	case 'd': {
			out.push_back(make_shared<MoveMe>(hero, Point(1, 0)));
			break;
		}
	case 'a': {
			out.push_back(make_shared<MoveMe>(hero, Point(-1, 0)));
			break;
		}
	case 'i': {
			out.push_back(make_shared<Shoot>(hero->getCord()+Point(0, -1), Point(0, -1), shared_ptr<Shoot::finc_t>(new Shoot::finc_t(&generator))));
			break;
		}
	case 'k': {
			out.push_back(make_shared<Shoot>(hero->getCord()+Point(0, 1), Point(0, 1), shared_ptr<Shoot::finc_t>(new Shoot::finc_t(&generator))));
			break;
		}
	case 'l': {
			out.push_back(make_shared<Shoot>(hero->getCord()+Point(1, 0), Point(1, 0), shared_ptr<Shoot::finc_t>(new Shoot::finc_t(&generator))));
			break;
		}
	case 'j': {
			out.push_back(make_shared<Shoot>(hero->getCord()+Point(-1, 0), Point(-1, 0), shared_ptr<Shoot::finc_t>(new Shoot::finc_t(&generator))));
			break;
		}

	}
	return out;
}

ComandList HeroAI::ColideWith(Hero * h, Princess * p)
{
	return ComandList();
}



