#include "pch.h"
#include "HeroAI.h"



shared_ptr<IProjectile> HeroAI::generator(Point p, Point dir)
{
	return make_shared<Hero::ShotType>(p, dir);
}

HeroAI::HeroAI(Hero* h): hero(h) {
	using t = std::pair<char, shared_ptr<IComand>>;
	Comands =
	{
		t('w',{make_shared<MoveMe>(hero, Point(0, -1))}),
		t('a',{make_shared<MoveMe>(hero, Point(-1, 0))}),
		t('s',{make_shared<MoveMe>(hero, Point(0, 1))}),
		t('d',{make_shared<MoveMe>(hero, Point(1, 0))}),
		t('i',{make_shared<Shoot>(hero, Point(0, -1), hero, shared_ptr<Shoot::func_t>(new Shoot::func_t(&generator)))}),
		t('j',{make_shared<Shoot>(hero, Point(-1, 0), hero, shared_ptr<Shoot::func_t>(new Shoot::func_t(&generator)))}),
		t('k',{make_shared<Shoot>(hero, Point(0, 1), hero, shared_ptr<Shoot::func_t>(new Shoot::func_t(&generator)))}),
		t('l',{make_shared<Shoot>(hero, Point(1, 0), hero, shared_ptr<Shoot::func_t>(new Shoot::func_t(&generator)))})
	};
}

ComandList HeroAI::getActions(const void *w, size_t comand)
{
	const Map *world = static_cast<const Map *>(w);
	if (Comands.count(comand))
	{
		return {Comands[comand]};
	}
	return {};
}

ComandList HeroAI::ColideWith(Hero * h, Princess * p)
{
	return ComandList();
}



